def extractCodeAndNote(file_path):
    with open(file_path, 'r') as file:
        lines = file.readlines()

    code_start_idx, code_end_idx = 0, 0
    note_start_idx, note_end_idx = 0, 0
    for idx, line in enumerate(lines):
        if "// @lc code=start" in line:
            code_start_idx = idx + 1

        if "// @lc code=end" in line:
            code_end_idx = idx

        if "// @castor solve=start" in line:
            note_start_idx = idx + 1

        if "// @castor solve=end" in line:
            note_end_idx = idx

    return "".join(lines[code_start_idx:code_end_idx]), "".join(lines[note_start_idx:note_end_idx])


if __name__ == '__main__':
    res = extractCodeAndNote("../LeetCode/71.简化路径.cpp")

    print("code: =======================")
    print(res[0])
    print("note: =======================")
    print(res[1])
