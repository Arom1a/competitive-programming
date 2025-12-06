import math

with open("input") as f:
    content = f.read().strip()

lines = content.split("\n")
longest = 0
for i in lines:
    longest = max(longest, len(i))
lines = [i + " " * (longest - len(i)) for i in lines]

wid = len(lines[0].split())
ans = 0
ops = lines[-1].split()
for w in range(wid):
    acc = 0
    if ops[w] == "*":
        acc = 1
        for line in lines[:-1]:
            acc *= int(line.split()[w])
    else:
        acc = 0
        for line in lines[:-1]:
            acc += int(line.split()[w])
    ans += acc
print(ans)

op_line = lines[-1]
index_of_op = []
for i in range(len(op_line)):
    if op_line[i] != " ":
        index_of_op.append(i)
index_of_op.append(longest + 1)

ans = 0
for n in range(wid):
    nums = []
    for idx in range(index_of_op[n], index_of_op[n + 1] - 1):
        num_str = ""
        for line in lines[:-1]:
            num_str += line[idx]
        nums.append(int(num_str.strip()))
    if ops[n] == "*":
        ans += math.prod(nums)
    else:
        ans += sum(nums)
print(ans)
