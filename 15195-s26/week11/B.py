import sys

# Increase recursion depth limit (Python's default is 1000, N=50 is fine, but good practice)
sys.setrecursionlimit(2000)

asdf = [[-1] * 1000 for _ in range(51)]


def calc(n, current_sum):
    if current_sum < 0:
        return 0
    if asdf[n][current_sum] != -1:
        return asdf[n][current_sum]
    if n == 1:
        ans = 1 if 0 <= current_sum <= 9 else 0
        asdf[n][current_sum] = ans
        return ans

    ans = 0
    for i in range(10):
        ans += calc(n - 1, current_sum - i)

    asdf[n][current_sum] = ans
    return ans


def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return

    N = int(input_data[0])
    S = int(input_data[1])

    if S % 2 == 1:
        print(0)
        return

    half = S // 2

    for i in range(51):
        for j in range(1005):
            asdf[i][j] = -1

    a = calc(N, half)
    print(a * a)


if __name__ == "__main__":
    solve()
