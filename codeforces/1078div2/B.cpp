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
    ll x, y;
    cin >> n >> x >> y;
    vll as(n);
    for (int i = 0; i < n; i++) {
        cin >> as[i];
    }

    vll trans(n);
    for (int i = 0; i < n; i++) {
        trans[i] = as[i] / x;
    }

    ll sum_trans = accumulate(all(trans), 0LL);
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        ans = max(ans, as[i] + (sum_trans - trans[i]) * y);
    }
    cout << ans << '\n';
}

int main() {
    fio;
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
}
