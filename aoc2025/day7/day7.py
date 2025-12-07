with open("input") as f:
    content = f.read().strip()

lines = content.split("\n")

starting_point = lines[0].find("S")
beams = set()
beams.add(starting_point)

ans = 0

for line in lines:
    splitters = []
    for i in range(len(line)):
        if line[i] == '^':
            splitters.append(i)
    if len(splitters) == 0:
        continue

    new_beams = set()
    used = set()
    for b in beams:
        if not (b in splitters):
            new_beams.add(b)
        for s in splitters:
            if b == s and s - 1 >= 0 and line[s - 1] == ".":
                used.add(s)
                new_beams.add(s - 1)
            if b == s and s + 1 <= len(line) and line[s + 1] == ".":
                used.add(s)
                new_beams.add(s + 1)
    ans += len(used)
    beams = new_beams

print(ans)

ans = 0
beams = set()
beams.add(starting_point)
dp = [0 for _ in lines[0]]
dp[starting_point] = 1

for line in lines:
    splitters = []
    for i in range(len(line)):
        if line[i] == '^':
            splitters.append(i)
    if len(splitters) == 0:
        continue

    new_beams = set()
    new_dp = [0 for _ in lines[0]]
    for b in beams:
        if not (b in splitters):
            new_dp[b] += dp[b]
            new_beams.add(b)
        for s in splitters:
            if b == s and s - 1 >= 0 and line[s - 1] == ".":
                new_dp[s - 1] += dp[s]
                new_beams.add(s - 1)
            if b == s and s + 1 <= len(line) and line[s + 1] == ".":
                new_dp[s + 1] += dp[s]
                new_beams.add(s + 1)
    dp = new_dp

    beams = new_beams

print(sum(dp))
