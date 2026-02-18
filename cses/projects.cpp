// https://cses.fi/problemset/task/1140
// dp, lower_bound

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
    int n;
    cin >> n;
    vec<array<int, 3>> ps(n);
    for (int i = 0; i < n; i++) {
        cin >> ps[i][1] >> ps[i][0] >> ps[i][2];
    }

    sort(all(ps));
    vec<array<ll, 2>> dp;
    dp.push_back({0, 0});
    ll m = 0;
    for (int i = 0; i < n; i++) {
        auto it = lower_bound(dp.begin(), dp.end(), array<ll, 2>{ps[i][1], 0});
        it--;
        m = max(m, (*it)[1] + ps[i][2]);

        dp.push_back({ps[i][0], m});
    }

    cout << dp[n][1] << '\n';
}

int main() {
    fio;
    int T = 1;
    while (T--) {
        solve();
    }
}
