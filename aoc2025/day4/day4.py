with open("input") as f:
    grid_str = f.read().strip()

grid = [list(row) for row in grid_str.splitlines()]
rows = len(grid)
cols = len(grid[0])

# 8 directions
dirs = [
    (-1, -1), (-1, 0), (-1, 1),
    (0, -1),         (0, 1),
    (1, -1), (1, 0), (1, 1)
]


def count_neighbors(r, c, g):
    cnt = 0
    for dr, dc in dirs:
        nr, nc = r + dr, c + dc
        if 0 <= nr < rows and 0 <= nc < cols:
            if g[nr][nc] == '@':
                cnt += 1
    return cnt


total = 0
for r in range(rows):
    for c in range(cols):
        if grid[r][c] == '@':
            if count_neighbors(r, c, grid) < 4:
                total += 1

print(total)


total_removed = 0

while True:
    to_remove = []
    for r in range(rows):
        for c in range(cols):
            if grid[r][c] == '@':
                if count_neighbors(r, c, grid) < 4:
                    to_remove.append((r, c))

    if not to_remove:
        break  # no more changes

    # apply removals
    for r, c in to_remove:
        grid[r][c] = '.'
    total_removed += len(to_remove)

print(total_removed)
