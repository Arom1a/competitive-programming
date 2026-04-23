import math

side, r = map(float, input().split())
hs = side / 2

ans = 0

if r > hs * math.sqrt(2):
    ans = side * side
else:
    ans = math.pi * (r**2)

    if r > hs:
        tri = math.sqrt(r**2 - hs**2) * hs
        arc = (math.acos(hs / r) * 2) / (2 * math.pi) * ans - tri
        ans -= 4 * arc

ans = round(ans, 3)
print(ans)
