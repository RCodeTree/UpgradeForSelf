import argparse
import asyncio
import os
import re
from dataclasses import dataclass
from typing import Iterable
from urllib.parse import urlparse

from playwright.async_api import async_playwright


@dataclass(frozen=True)
class CrawlOptions:
    url: str
    out_dir: str
    headless: bool
    max_scroll_steps: int
    scroll_px: int
    wait_ms: int
    stable_rounds: int
    timeout_ms: int


def _guess_ext(url: str) -> str:
    path = urlparse(url).path
    m = re.search(r"\.(png|jpg|jpeg|webp|gif)$", path, re.IGNORECASE)
    if m:
        return "." + m.group(1).lower()
    return ".png"


def _page_no_from_url(url: str) -> int | None:
    path = urlparse(url).path
    m = re.search(r"/(\d+)\.(png|jpg|jpeg|webp|gif)$", path, re.IGNORECASE)
    if not m:
        return None
    try:
        return int(m.group(1))
    except ValueError:
        return None


def _dedupe_keep_order(items: Iterable[str]) -> list[str]:
    seen: set[str] = set()
    out: list[str] = []
    for it in items:
        if it in seen:
            continue
        seen.add(it)
        out.append(it)
    return out


async def _collect_image_urls(page) -> list[str]:
    urls = await page.evaluate(
        r"""() => {
            const nodes = Array.from(document.querySelectorAll('img'));
            const list = [];
            for (const img of nodes) {
                const u = img.getAttribute('data_src') || img.getAttribute('data-src') || img.getAttribute('src');
                if (!u) continue;
                if (/^https?:\/\//i.test(u)) list.push(u);
            }
            return Array.from(new Set(list));
        }"""
    )
    return [u for u in urls if isinstance(u, str)]


async def _scroll_until_stable(page, opts: CrawlOptions) -> list[str]:
    last_count = -1
    stable = 0
    collected: list[str] = []

    for _ in range(opts.max_scroll_steps):
        await page.mouse.wheel(0, opts.scroll_px)
        await page.wait_for_timeout(opts.wait_ms)

        urls = await _collect_image_urls(page)
        urls = _dedupe_keep_order(urls)
        collected = urls

        if len(urls) == last_count:
            stable += 1
        else:
            stable = 0
            last_count = len(urls)

        if stable >= opts.stable_rounds:
            break

    return collected


async def _download_all(context, urls: list[str], out_dir: str) -> list[str]:
    os.makedirs(out_dir, exist_ok=True)

    numbered: list[tuple[int, str]] = []
    unnumbered: list[str] = []

    for u in urls:
        no = _page_no_from_url(u)
        if no is None:
            unnumbered.append(u)
        else:
            numbered.append((no, u))

    numbered.sort(key=lambda x: x[0])
    ordered = [u for _, u in numbered] + unnumbered
    saved: list[str] = []

    for idx, u in enumerate(ordered, start=1):
        page_no = _page_no_from_url(u)
        ext = _guess_ext(u)
        name = f"{idx:03d}{ext}" if page_no is None else f"page_{page_no:03d}{ext}"
        file_path = os.path.join(out_dir, name)

        resp = await context.request.get(u)
        if not resp.ok:
            continue
        data = await resp.body()
        with open(file_path, "wb") as f:
            f.write(data)
        saved.append(file_path)

    return saved


async def run(opts: CrawlOptions) -> int:
    async with async_playwright() as p:
        browser = await p.chromium.launch(headless=opts.headless)
        context = await browser.new_context()
        page = await context.new_page()

        await page.goto(opts.url, wait_until="networkidle", timeout=opts.timeout_ms)
        urls = await _scroll_until_stable(page, opts)
        urls = [u for u in urls if "/thumb/" in u or u.lower().endswith((".png", ".jpg", ".jpeg", ".webp", ".gif"))]
        urls = _dedupe_keep_order(urls)

        saved = await _download_all(context, urls, opts.out_dir)
        await browser.close()

    print(f"images_found={len(urls)}")
    print(f"images_saved={len(saved)}")
    print(f"out_dir={opts.out_dir}")
    return 0


def parse_args() -> CrawlOptions:
    parser = argparse.ArgumentParser()
    parser.add_argument("--url", required=True)
    parser.add_argument("--out", default=os.path.join(os.getcwd(), "chaoxing_images"))
    parser.add_argument("--headed", action="store_true")
    parser.add_argument("--max-scroll", type=int, default=80)
    parser.add_argument("--scroll-px", type=int, default=1600)
    parser.add_argument("--wait-ms", type=int, default=250)
    parser.add_argument("--stable-rounds", type=int, default=8)
    parser.add_argument("--timeout-ms", type=int, default=60000)
    args = parser.parse_args()

    return CrawlOptions(
        url=args.url,
        out_dir=args.out,
        headless=not args.headed,
        max_scroll_steps=args.max_scroll,
        scroll_px=args.scroll_px,
        wait_ms=args.wait_ms,
        stable_rounds=args.stable_rounds,
        timeout_ms=args.timeout_ms,
    )


def main() -> int:
    opts = parse_args()
    return asyncio.run(run(opts))


if __name__ == "__main__":
    raise SystemExit(main())
