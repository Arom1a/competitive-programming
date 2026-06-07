#include <bits/stdc++.h>

using namespace std;
#define all(a) a.begin(), a.end()
template <typename T>
using vec = vector<T>;
using ll = long long;
using vi = vec<int>;
using vvi = vec<vi>;
using vll = vec<ll>;
using vvll = vec<vll>;
using vb = vec<bool>;
using vvb = vec<vb>;
using vc = vec<char>;
using vvc = vec<vc>;
using vs = vec<string>;
using vvs = vec<vs>;
template <typename T>
using max_heap = priority_queue<T>;
template <typename T>
using min_heap = priority_queue<T, vector<T>, greater<T>>;

void solve() {
    int n, x, s;
    cin >> n >> x >> s;
    string u;
    cin >> u;

    vi dp(x + 1, -1);
    dp[0] = 0;

    for (int i = 0; i < n; i++) {
        char c = u[i];

        for (int k = min(i + 1, x); k >= 0; k--) {
            int best = dp[k];  // drop

            // assign to enpty
            if ((c == 'I' || c == 'A') && k > 0 && dp[k - 1] != -1) {
                best = max(best, dp[k - 1] + 1);
            }

            // assign to non-empty
            if ((c == 'E' || c == 'A') && dp[k] != -1) {
                ll tmp = k * s;
                if (dp[k] < tmp) {
                    best = max(best, dp[k] + 1);
                }
            }

            dp[k] = best;
        }
    }

    int ans = 0;
    for (int& i : dp) {
        ans = max(ans, i);
    }
    cout << ans << endl;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
}
