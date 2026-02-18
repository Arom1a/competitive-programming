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

void solve() {
    int n, x;
    cin >> n >> x;
    vi cs(n);
    for (int i = 0; i < n; i++) {
        cin >> cs[i];
    }
    vi dp(x + 1, x + 1);
    dp[0] = 0;
    for (int i = 0; i <= x; i++) {
        for (int& j : cs) {
            if (i - j < 0) continue;
            dp[i] = min(dp[i], dp[i - j] + 1);
        }
    }
    if (dp[x] == x + 1) cout << -1 << '\n';
    else cout << dp[x] << '\n';
}

int main() {
    fio;
    int T = 1;
    while (T--) {
        solve();
    }
}
