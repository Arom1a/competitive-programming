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
    int n;
    cin >> n;
    vll hs(n);
    for (int i = 0; i < n; i++) {
        cin >> hs[i];
    }

    vi mhs(n);
    mhs.reserve(n);
    ll left_h = hs.back();
    for (ll i = 0; i < n; i++) {
        mhs[i] = min(left_h, hs[i]);
        left_h = hs[i];
    }

    for (ll i = 0; i < n; i++) {
        // cout << mhs[i] << ' ';

        vi toright(n);
        ll max_seen = hs[i];
        for (ll idx_j = 1; idx_j < n; idx_j++) {
            ll j = (idx_j + i) % n;
            toright[j] = max_seen;
            max_seen = max(max_seen, hs[j]);
        }

        vi toleft(n);
        max_seen = hs[(i + n - 1) % n];
        for (ll idx_j = n - 1; idx_j > 0; idx_j--) {
            ll j = (idx_j + i) % n;
            toleft[j] = max_seen;
            max_seen = max(max_seen, hs[(j + n - 1) % n]);
        }

        // for (int j = 0; j < n; j++) {
        //     if (j == i) {
        //         cout << 0 << ' ';
        //     } else {
        //         cout << min(toright[j], toleft[j]) << ' ';
        //     }
        // }
        // cout << "\n";

        ll ans = 0;
        for (ll j = 0; j < n; j++) {
            if (j == i) continue;
            ans += min(toright[j], toleft[j]);
        }
        cout << ans << ' ';
    }
    cout << endl;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
}
