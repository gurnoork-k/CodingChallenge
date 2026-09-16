import os
import re

REPO_ROOT = "."
README_PATH = "README.md"

IGNORE = {".git", ".github", "scripts", "node_modules"}

PLATFORMS = {
    "leetcode":   {"folder": "leetcode",   "marker": "LEETCODE",   "title": "LeetCode",      "numbered": True},
    "gfg":        {"folder": "gfg",        "marker": "GFG",        "title": "GeeksforGeeks", "numbered": False},
    "hackerrank": {"folder": "hackerrank", "marker": "HACKERRANK", "title": "HackerRank",    "numbered": False},
    "codechef":   {"folder": "codechef",   "marker": "CODECHEF",   "title": "CodeChef",      "numbered": False},
}


def get_problem_folders(base_folder, numbered):
    """Walk only inside base_folder. If numbered=True, expects \\d{4}-slug names.
    If numbered=False, accepts any slug folder (no digit prefix required)."""
    if not os.path.isdir(base_folder):
        return []

    pattern = r"^\d{4}-" if numbered else r"^[a-zA-Z0-9]"
    folders = []
    for root, dirs, files in os.walk(base_folder):
        dirs[:] = [d for d in dirs if d not in IGNORE and not d.startswith(".")]
        for name in dirs:
            if re.match(pattern, name):
                rel_path = os.path.relpath(os.path.join(root, name), REPO_ROOT)
                folders.append(rel_path)

    if numbered:
        return sorted(folders, key=lambda x: int(os.path.basename(x).split("-")[0]))
    else:
        return sorted(folders, key=lambda x: os.path.basename(x).lower())


def folder_to_title(folder, numbered):
    base = os.path.basename(folder)
    parts = base.split("-")[1:] if numbered else base.split("-")
    return " ".join(p.capitalize() for p in parts)


def build_table(folders, numbered):
    if not folders:
        return "_No problems solved yet._"
    rows = ["| # | Problem | Folder |", "|---|---------|--------|"]
    for i, folder in enumerate(folders, start=1):
        base = os.path.basename(folder)
        num = str(int(base.split("-")[0])) if numbered else str(i)
        title = folder_to_title(folder, numbered)
        rows.append(f"| {num} | {title} | [{folder}](./{folder}) |")
    return "\n".join(rows)


def update_readme(tables_by_platform):
    with open(README_PATH, "r") as f:
        content = f.read()

    for key, info in PLATFORMS.items():
        marker = info["marker"]
        start_marker = f"<!-- {marker}_TABLE_START -->"
        end_marker = f"<!-- {marker}_TABLE_END -->"
        table = tables_by_platform[key]

        new_section = f"{start_marker}\n{table}\n{end_marker}"

        if start_marker in content and end_marker in content:
            content = re.sub(
                f"{re.escape(start_marker)}.*?{re.escape(end_marker)}",
                new_section,
                content,
                flags=re.DOTALL
            )
        else:
            content += f"\n\n## {info['title']}\n{new_section}\n"

    with open(README_PATH, "w") as f:
        f.write(content)


if __name__ == "__main__":
    tables_by_platform = {}
    total = 0

    for key, info in PLATFORMS.items():
        folders = get_problem_folders(info["folder"], info["numbered"])
        tables_by_platform[key] = build_table(folders, info["numbered"])
        total += len(folders)
        print(f"{info['title']}: {len(folders)} problems")

    update_readme(tables_by_platform)
    print(f"Updated README with {total} problems across {len(PLATFORMS)} platforms.")
