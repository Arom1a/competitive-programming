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
    ll h;
    int n, k;
    cin >> n >> h >> k;
    vi as(n);
    for (int i = 0; i < n; i++) {
        cin >> as[i];
    }

    ll sum = accumulate(all(as), 0LL);
    if (h % sum == 0) {
        cout << (h / sum) * (n + k) - k << '\n';
        return;
    }
    ll ans = 0;
    ans += (h / sum) * (n + k);
    h %= sum;

    vll max_possi_till_i(n);
    vll prefix_min(n, LONG_LONG_MAX);
    vll suffix_max(n, 0);
    ll min_current = LONG_LONG_MAX;
    ll max_current = 0;
    for (int i = 0; i < n; i++) {
        min_current = min(min_current, (ll)as[i]);
        prefix_min[i] = min_current;
    }
    for (int i = n - 1; i >= 1; i--) {
        max_current = max(max_current, (ll)as[i]);
        suffix_max[i - 1] = max_current;
    }
    for (int i = n - 1; i >= 0; i--) {
        max_possi_till_i[i] = sum - prefix_min[i] + max(suffix_max[i], prefix_min[i]);
        sum -= as[i];
    }

    for (int i = 0; i < n; i++) {
        if (max_possi_till_i[i] >= h) {
            ans += i + 1;
            break;
        }
    }
    // for (int i = 0; i < n; i++) {
    //     cout << prefix_min[i] << ' ';
    // }
    // cout << '\n';
    // for (int i = 0; i < n; i++) {
    //     cout << suffix_max[i] << ' ';
    // }
    // cout << '\n';
    // for (int i = 0; i < n; i++) {
    //     cout << max_possi_till_i[i] << ' ';
    // }
    // cout << '\n';
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
