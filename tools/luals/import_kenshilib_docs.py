"""Import concise class and method summaries from KenshiLib Markdown docs.

The docs repository is intentionally an input, not a runtime dependency. This
tool extracts the human-written summaries into a checked-in JSON artifact used
by the LuaLS definition generator.

Usage:
    python tools/luals/import_kenshilib_docs.py --docs C:/path/to/docs
"""

import argparse
import json
import pathlib
import re


PROJECT_ROOT = pathlib.Path(__file__).resolve().parents[2]
OUTPUT_PATH = PROJECT_ROOT / "luals" / "metadata" / "kenshilib_descriptions.json"


def clean_summary(text):
    text = re.sub(r"```.*?```", "", text, flags=re.DOTALL)
    text = re.sub(r"^\|.*$", "", text, flags=re.MULTILINE)
    text = re.sub(r"^\*\*(?:RVA|VTable|Calling Convention).*?$", "", text, flags=re.MULTILINE)
    text = text.split("**Reverse-Engineered Logic & Implementation:**", 1)[0]
    text = text.split("**Parameters:**", 1)[0]
    text = text.split("**Returns:**", 1)[0]
    paragraphs = [
        re.sub(r"\s+", " ", paragraph.strip())
        for paragraph in re.split(r"\n\s*\n", text)
        if paragraph.strip()
    ]
    if not paragraphs:
        return ""
    # The final paragraph before Parameters/Returns is the method summary;
    # earlier paragraphs are usually signature metadata or code fences.
    return paragraphs[-1]


def parse_memory_layout(text):
    section = re.search(
        r"^## Memory Layout\s*$\n(.*?)(?=^##\s|\Z)", text, re.MULTILINE | re.DOTALL
    )
    if not section:
        return {}
    properties = {}
    for line in section.group(1).splitlines():
        if not line.startswith("|"):
            continue
        cells = [cell.strip() for cell in line.strip().strip("|").split("|")]
        if len(cells) < 4 or not cells[0].startswith("`"):
            continue
        member_match = re.fullmatch(r"`([^`]+)`", cells[2])
        if not member_match:
            continue
        description = re.sub(r"\s+", " ", cells[3]).strip()
        if description:
            properties[member_match.group(1)] = description
    return properties


def parse_page(path):
    text = path.read_text(encoding="utf-8", errors="ignore")
    class_match = re.search(r"^class:\s*([^\n]+)", text, re.MULTILINE)
    if not class_match:
        return None, "", {}, {}
    class_name = class_match.group(1).strip()
    body_start = text.find("---", class_match.end())
    body = text[body_start + 3:] if body_start >= 0 else text
    title_match = re.search(r"^#\s+[^\n]+\n", body, re.MULTILINE)
    class_summary = ""
    if title_match:
        class_summary = clean_summary(body[title_match.end():].split("---", 1)[0])

    headings = list(re.finditer(r"^### `([^`]+)`\s*$", text, re.MULTILINE))
    methods = {}
    for index, heading in enumerate(headings):
        end = headings[index + 1].start() if index + 1 < len(headings) else len(text)
        heading_name = heading.group(1).split("(", 1)[0].strip()
        summary = clean_summary(text[heading.end():end])
        if heading_name and summary and heading_name not in methods:
            methods[heading_name] = summary
    return class_name, class_summary, methods, parse_memory_layout(text)


def import_docs(docs_root):
    classes = {}
    for page in sorted(docs_root.glob("api/*.md")):
        class_name, class_summary, methods, properties = parse_page(page)
        if not class_name or class_name.startswith("<"):
            continue
        entry = classes.setdefault(class_name, {"description": "", "methods": {}, "properties": {}})
        if class_summary and not entry["description"]:
            entry["description"] = class_summary
        entry["methods"].update(methods)
        entry["properties"].update(properties)
    return {"source": "KenshiLib-docs/docs", "classes": dict(sorted(classes.items()))}


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument("--docs", required=True, type=pathlib.Path)
    args = parser.parse_args()
    if not args.docs.is_dir():
        parser.error("docs directory does not exist: " + str(args.docs))
    artifact = import_docs(args.docs)
    OUTPUT_PATH.write_text(json.dumps(artifact, indent=2, ensure_ascii=False) + "\n", encoding="utf-8")
    classes = artifact["classes"]
    methods = sum(len(entry["methods"]) for entry in classes.values())
    print("Imported {0} classes and {1} method descriptions.".format(len(classes), methods))


if __name__ == "__main__":
    main()
