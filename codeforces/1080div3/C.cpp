#include <bits/stdc++.h>

using namespace std;
#define all(a) a.begin(), a.end()
#define fio                  \
    ios::sync_with_stdio(0); \
    cin.tie(NULL)
template <typename T>
using vec = vector<T>;
typedef long long ll;
typedef vec<int> vi;
typedef vec<vec<int>> vvi;
typedef vec<ll> vll;
typedef vec<vec<ll>> vvll;
typedef vec<bool> vb;
typedef vec<vec<bool>> vvb;
typedef vec<string> vs;
typedef vec<vec<string>> vvs;

int nums[] = {1, 2, 3, 4, 5, 6};

void solve() {
    int n;
    cin >> n;
    vi as(n);
    for (int i = 0; i < n; i++) {
        cin >> as[i];
    }
    vvi dp(n, vi(7, INT_MAX));
    for (const auto& i : nums) {
        dp[0][i] = as[0] == i ? 0 : 1;
    }

    for (int i = 1; i < n; i++) {
        for (const auto& j : nums) {
            int prev_min = INT_MAX;
            for (const auto& k : nums) {
                if (j != k && j + k != 7) {
                    prev_min = min(prev_min, dp[i - 1][k]);
                }
            }
            dp[i][j] = (as[i] == j ? 0 : 1) + prev_min;
        }
    }

    cout << *min_element(all(dp[n - 1])) << '\n';
}

int main() {
    fio;
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
}
