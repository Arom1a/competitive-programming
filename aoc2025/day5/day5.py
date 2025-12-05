with open("input") as f:
    content = f.read().strip()

empty_line_idx = content.find("\n\n")
tag_str = content[0:empty_line_idx].strip()
tags = []
for line in tag_str.split("\n"):
    idx = line.find("-")
    tags.append((int(line[:idx]), int(line[idx + 1:])))
tags.sort()

ans = 0

checks = content[empty_line_idx + 1:].strip()
for line in checks.split("\n"):
    n = int(line)
    for i in tags:
        if i[0] <= n and n <= i[1]:
            ans += 1
            break

print(ans)

l, r = tags[0][0], tags[0][1]
ans = 0
for i in range(len(tags) - 1):
    i = i + 1
    li, ri = tags[i][0], tags[i][1]
    if r >= li:
        r = max(r, ri)
    else:
        ans += r - l + 1
        l, r = li, ri

ans += r - l + 1

print(ans)
