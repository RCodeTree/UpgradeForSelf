import re
import os

file_path = r"d:\Windows Defalt\桌面\UpgradeForSelf\英语\test.md"
output_path = r"d:\Windows Defalt\桌面\UpgradeForSelf\英语\test.html"

with open(file_path, 'r', encoding='utf-8') as f:
    lines = f.readlines()

html_lines = []
html_lines.append('<html><head><meta charset="utf-8"><style>body { font-family: "Times New Roman", "SimSun", serif; line-height: 1.5; } p { margin: 0.5em 0; } table { border-collapse: collapse; width: 100%; } th, td { border: 1px solid black; padding: 8px; text-align: left; }</style></head><body>')

for line in lines:
    line = line.rstrip()
    stripped = line.lstrip()
    
    if not stripped:
        continue
        
    # Handle Bold
    # Regex to replace **text** with <b>text</b>
    # Note: simple non-greedy match
    line = re.sub(r'\*\*(.*?)\*\*', r'<b>\1</b>', line)
    
    # Handle Headers
    if stripped.startswith('### '):
        content = stripped[4:]
        html_lines.append(f'<h3>{content}</h3>')
        continue
        
    # Handle existing HTML tags
    # Heuristic: if it starts with <, assume it is HTML.
    # Exception: if it's < 5 (math), but here we deal with text.
    # The user has <p>, <div>, <table>, <tr>, <td>, <th>, <br>
    if stripped.startswith('<'):
        html_lines.append(line)
        continue
        
    # Handle normal text
    # Wrap in <p>
    html_lines.append(f'<p>{line}</p>')

html_lines.append('</body></html>')

with open(output_path, 'w', encoding='utf-8') as f:
    f.write('\n'.join(html_lines))

print("HTML generated.")
