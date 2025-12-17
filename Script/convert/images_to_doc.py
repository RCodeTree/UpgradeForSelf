import argparse
import io
import os
from dataclasses import dataclass

import img2pdf
from PIL import Image


@dataclass(frozen=True)
class SliceOptions:
    blank_threshold: int
    content_threshold: int
    min_blank_run: int
    min_slice_height: int
    padding: int
    trim: bool
    slice_pages: bool
    detect_red_line: bool
    fixed_split_x: int


def _list_images(input_dir: str) -> list[str]:
    exts = (".png", ".jpg", ".jpeg", ".webp")
    files = [f for f in os.listdir(input_dir) if f.lower().endswith(exts)]
    files.sort()
    return [os.path.join(input_dir, f) for f in files]


def _ensure_rgb(img: Image.Image) -> Image.Image:
    if img.mode in ("RGBA", "LA"):
        bg = Image.new("RGBA", img.size, (255, 255, 255, 255))
        merged = Image.alpha_composite(bg, img.convert("RGBA"))
        return merged.convert("RGB")
    if img.mode != "RGB":
        return img.convert("RGB")
    return img


def _trim_whitespace(img: Image.Image, content_threshold: int, padding: int) -> Image.Image:
    gray = img.convert("L")
    mask = gray.point(lambda p: 255 if p < content_threshold else 0, mode="1")
    bbox = mask.getbbox()
    if not bbox:
        return img
    left, top, right, bottom = bbox
    left = max(0, left - padding)
    top = max(0, top - padding)
    right = min(img.width, right + padding)
    bottom = min(img.height, bottom + padding)
    if right <= left or bottom <= top:
        return img
    return img.crop((left, top, right, bottom))


def _find_blank_row_splits(img: Image.Image, blank_threshold: int, min_blank_run: int) -> list[int]:
    gray = img.convert("L")
    w, h = gray.size
    pix = gray.load()

    blank_rows = [False] * h
    for y in range(h):
        s = 0
        for x in range(w):
            s += pix[x, y]
        blank_rows[y] = (s / w) >= blank_threshold

    splits: list[int] = []
    y = 0
    while y < h:
        if not blank_rows[y]:
            y += 1
            continue
        start = y
        while y < h and blank_rows[y]:
            y += 1
        end = y
        if end - start >= min_blank_run:
            splits.append((start + end) // 2)
    return splits


def _detect_red_line_x(img: Image.Image) -> int:
    """
    Scans the image for a vertical red line.
    Returns the x-coordinate of the line, or -1 if not found.
    """
    rgb = _ensure_rgb(img)
    w, h = rgb.size
    pix = rgb.load()

    # Heuristic for "Red": High R, low G and B.
    # We'll scan the middle 80% of the width.
    start_x = int(w * 0.1)
    end_x = int(w * 0.9)
    step_y = max(1, h // 50)  # Sample 50 points vertically

    max_red_score = 0
    best_x = -1

    for x in range(start_x, end_x):
        red_score = 0
        for y in range(0, h, step_y):
            r, g, b = pix[x, y]
            # Red criteria: R significantly higher than G and B
            if r > 140 and g < 100 and b < 100:
                red_score += 1
        
        # If this column has more red pixels than current max
        if red_score > max_red_score:
            max_red_score = red_score
            best_x = x

    # Threshold: At least 20% of sampled points must be red to count as a line
    min_score = (h // step_y) * 0.2
    if max_red_score > min_score:
        return best_x
    
    return -1


def _slice_image(img: Image.Image, opts: SliceOptions) -> list[Image.Image]:
    # 1. Vertical Split (Red Line or Fixed X)
    pieces = [img]
    split_x = -1
    
    if opts.fixed_split_x > 0:
        split_x = opts.fixed_split_x
    elif opts.detect_red_line:
        split_x = _detect_red_line_x(img)
        if split_x != -1:
            print(f"Detected red line at x={split_x}")

    if split_x > 0 and split_x < img.width:
        # Split into Left and Right
        left = img.crop((0, 0, split_x, img.height))
        # Optional: Skip the line width? Assuming 1-2px, maybe start at split_x + 1?
        # For safety, just start at split_x.
        right = img.crop((split_x, 0, img.width, img.height))
        pieces = [left, right]

    # 2. Horizontal Split & Trim (per piece)
    final_slices: list[Image.Image] = []
    
    for p in pieces:
        # If we need to slice pages horizontally (blank rows)
        sub_slices = []
        if opts.slice_pages:
            splits = _find_blank_row_splits(p, opts.blank_threshold, opts.min_blank_run)
            boundaries = [0] + splits + [p.height]
            
            for i in range(len(boundaries) - 1):
                top = boundaries[i]
                bottom = boundaries[i + 1]
                if bottom - top < opts.min_slice_height:
                    continue
                chunk = p.crop((0, top, p.width, bottom))
                sub_slices.append(chunk)
                
            if not sub_slices:
                sub_slices = [p]
        else:
            sub_slices = [p]

        # Process each sub-slice (Trim, Ensure RGB)
        for chunk in sub_slices:
            out = _ensure_rgb(chunk)
            if opts.trim:
                out = _trim_whitespace(out, opts.content_threshold, opts.padding)
            final_slices.append(out)

    return final_slices


def _images_to_pdf_bytes(images: list[Image.Image]) -> bytes:
    buffers: list[io.BytesIO] = []
    for im in images:
        bio = io.BytesIO()
        im.save(bio, format="PNG")
        bio.seek(0)
        buffers.append(bio)
    return img2pdf.convert(buffers)


def convert_dir_images_sliced_to_pdf(input_dir: str, output_pdf: str, opts: SliceOptions) -> tuple[int, int]:
    if not os.path.isdir(input_dir):
        raise FileNotFoundError(f"input_dir not found: {input_dir}")

    paths = _list_images(input_dir)
    if not paths:
        raise FileNotFoundError(f"no images found in: {input_dir}")

    sliced_pages: list[Image.Image] = []
    for p in paths:
        print(f"Processing: {p}")
        with Image.open(p) as img:
            img.load()
            # Copy to detach from file so we can close it safely
            temp_img = img.copy()
            sliced_pages.extend(_slice_image(temp_img, opts))

    pdf_bytes = _images_to_pdf_bytes(sliced_pages)
    os.makedirs(os.path.dirname(output_pdf) or ".", exist_ok=True)
    with open(output_pdf, "wb") as f:
        f.write(pdf_bytes)

    return (len(paths), len(sliced_pages))


def parse_args() -> argparse.Namespace:
    parser = argparse.ArgumentParser()
    parser.add_argument(
        "--input",
        default=r"d:\Windows Defalt\桌面\UpgradeForSelf\Script\convert\image",
    )
    parser.add_argument(
        "--output",
        default=r"d:\Windows Defalt\桌面\UpgradeForSelf\Script\convert\image_sliced.pdf",
    )
    parser.add_argument("--no-slice", action="store_true", help="Disable horizontal slicing")
    parser.add_argument("--no-trim", action="store_true", help="Disable whitespace trimming")
    parser.add_argument("--blank-threshold", type=int, default=245)
    parser.add_argument("--content-threshold", type=int, default=250)
    parser.add_argument("--min-blank-run", type=int, default=30)
    parser.add_argument("--min-slice-height", type=int, default=200)
    parser.add_argument("--padding", type=int, default=10)
    
    # New arguments for vertical splitting
    parser.add_argument("--detect-red-line", action="store_true", help="Auto-detect vertical red line to split page")
    parser.add_argument("--split-x", type=int, default=-1, help="Fixed X coordinate for vertical split")

    return parser.parse_args()


def main() -> int:
    args = parse_args()
    opts = SliceOptions(
        blank_threshold=args.blank_threshold,
        content_threshold=args.content_threshold,
        min_blank_run=args.min_blank_run,
        min_slice_height=args.min_slice_height,
        padding=args.padding,
        trim=not args.no_trim,
        slice_pages=not args.no_slice,
        detect_red_line=args.detect_red_line,
        fixed_split_x=args.split_x,
    )

    src_count, page_count = convert_dir_images_sliced_to_pdf(args.input, args.output, opts)
    print(f"images_input={src_count}")
    print(f"pages_output={page_count}")
    print(f"pdf={args.output}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
