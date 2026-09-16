import os
import re

REPO_ROOT = "."
README_PATH = "README.md"

IGNORE = {".git", ".github", "scripts", "node_modules"}

# Add/remove platforms here — folder name must match your repo's top-level dir
PLATFORMS = {
    "leetcode":   {"folder": "leetcode",   "marker": "LEETCODE",   "title": "LeetCode"},
    "gfg":        {"folder": "gfg",        "marker": "GFG",        "title": "GeeksforGeeks"},
    "hackerrank": {"folder": "hackerrank", "marker": "HACKERRANK", "title": "HackerRank"},
    "codechef":   {"folder": "codechef",   "marker": "CODECHEF",   "title": "CodeChef"},
}


def get_problem_folders(base_folder):
    """Walk only inside base_folder (e.g. 'leetcode') and find \\d{4}-slug dirs."""
    if not os.path.isdir(base_folder):
        return []

    folders = []
    for root, dirs, files in os.walk(base_folder):
        dirs[:] = [d for d in dirs if d not in IGNORE and not d.startswith(".")]
        for name in dirs:
            if re.match(r"^\d{4}-", name):
                rel_path = os.path.relpath(os.path.join(root, name), REPO_ROOT)
                folders.append(rel_path)

    return sorted(folders, key=lambda x: int(os.path.basename(x).split("-")[0]))


def folder_to_title(folder):
    base = os.path.basename(folder)
    parts = base.split("-")[1:]
    return " ".join(p.capitalize() for p in parts)


def build_table(folders):
    if not folders:
        return "_No problems solved yet._"
    rows = ["| # | Problem | Folder |", "|---|---------|--------|"]
    for folder in folders:
        base = os.path.basename(folder)
        num = str(int(base.split("-")[0]))
        title = folder_to_title(folder)
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
            # marker missing -> append a new section for this platform
            content += f"\n\n## {info['title']}\n{new_section}\n"

    with open(README_PATH, "w") as f:
        f.write(content)


if __name__ == "__main__":
    tables_by_platform = {}
    total = 0

    for key, info in PLATFORMS.items():
        folders = get_problem_folders(info["folder"])
        tables_by_platform[key] = build_table(folders)
        total += len(folders)
        print(f"{info['title']}: {len(folders)} problems")

    update_readme(tables_by_platform)
    print(f"Updated README with {total} problems across {len(PLATFORMS)} platforms.")
