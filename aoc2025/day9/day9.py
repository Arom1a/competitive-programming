from shapely.geometry import Polygon, box
from itertools import combinations

with open("input") as f:
    content = f.read().strip()


def process(s):
    a = s.split(",")
    return (int(a[0]), int(a[1]))


tiles = list(map(
    process,
    content.split("\n")
))

ans = 0

for i in range(len(tiles)):
    for j in range(i + 1, len(tiles)):
        new = (abs(tiles[i][0] - tiles[j][0]) + 1) * \
            abs((tiles[i][1] - tiles[j][1]) + 1)
        ans = max(ans, new)

print(ans)

# tile_xs = [i[0] for i in tiles]
# tile_ys = [i[1] for i in tiles]
#
# min_x = min(tile_xs)
# max_x = max(tile_xs) - min_x
# min_y = min(tile_ys)
# max_y = max(tile_ys) - min_y
#
# tile_xs = [i - min_x for i in tile_xs]
# tile_ys = [i - min_y for i in tile_ys]
#
# print(tile_xs)
# print(tile_ys)
#
# tile_xs.append(tile_xs[0])
# tile_ys.append(tile_ys[0])
#
# print(max_x)
# print(max_y)
# is_gor = [[0 for _ in range(max_x + 1)] for _ in range(max_y + 1)]
# for i in range(len(tile_xs) - 1):
#     if tile_xs[i] == tile_xs[i + 1]:
#         y1 = tile_ys[i]
#         y2 = tile_ys[i + 1]
#         for j in range(min(y1, y2), max(y1, y2) + 1):
#             is_gor[j][tile_xs[i]] = 1
#     else:
#         x1 = tile_xs[i]
#         x2 = tile_xs[i + 1]
#         for j in range(min(x1, x2), max(x1, x2) + 1):
#             is_gor[tile_ys[i]][j] = 1
#
# dir = [
#     [0, 1],
#     [0, -1],
#     [1, 0],
#     [-1, 0],
# ]
#
#
# def ff(sx, sy):
#     global is_gor
#     q = deque()
#     q.append((sx, sy))
#     while len(q) != 0:
#         (nx, ny) = q.popleft()
#         is_gor[ny][nx] = 1
#         for (dx, dy) in dir:
#             if is_gor[ny + dy][nx + dx] == 1:
#                 continue
#             q.append((nx + dx, ny + dy))

with open("input") as f:
    # distinct list of (x, y) tuples
    coords = [tuple(map(int, line.split(','))) for line in f if ',' in line]

poly = Polygon(coords)


def get_area(p):
    (x1, y1), (x2, y2) = p
    return (abs(x2 - x1) + 1) * (abs(y2 - y1) + 1)


for pair in sorted(combinations(coords, 2), key=get_area, reverse=True):
    (x1, y1), (x2, y2) = pair
    rect = box(min(x1, x2), min(y1, y2), max(x1, x2), max(y1, y2))
    if poly.covers(rect):
        print(get_area(pair))
        break
