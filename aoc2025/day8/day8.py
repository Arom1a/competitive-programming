with open("input") as f:
    content = f.read().strip()

nums = []
for i in content.split("\n"):
    nums.append(tuple(map(int, i.split(","))))

dist = []
for i in range(len(nums)):
    for j in range(i + 1, len(nums)):
        dx = nums[i][0] - nums[j][0]
        dy = nums[i][1] - nums[j][1]
        dz = nums[i][2] - nums[j][2]
        dist.append((dx ** 2 + dy ** 2 + dz**2, (i, j)))
dist = sorted(dist, key=lambda x: x[0])

uf = [i for i in range(len(nums))]
size = [1 for i in range(len(nums))]

count = len(nums)


def find(i):
    if i == uf[i]:
        return i
    uf[i] = find(uf[i])
    return uf[i]


def union(i, j):
    global count
    ri = find(i)
    rj = find(j)
    if ri == rj:
        return
    if size[ri] < size[rj]:
        uf[ri] = rj
        size[rj] += size[ri]
    else:
        uf[rj] = ri
        size[ri] += size[rj]
    count -= 1


for i in range(1000):
    (d, (e1, e2)) = dist[i]
    union(e1, e2)

size_sorted = sorted(size, reverse=True)
print(size_sorted[0] * size_sorted[1] * size_sorted[2])

i = 1001
last1 = 0
last2 = 0
while count != 1:
    (d, (e1, e2)) = dist[i]
    union(e1, e2)
    last1, last2 = e1, e2
    i += 1

print(nums[last1][0] * nums[last2][0])
