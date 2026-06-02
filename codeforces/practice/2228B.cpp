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
    int n, x1, x2, k;
    cin >> n >> x1 >> x2 >> k;
    // imagine reimu(x1) at 0 oclock and remilia at 6 oclock
    // cw is to the right of reimu, ccw is to the left
    int dist_cw, dist_ccw;
    if (x1 < x2) {
        dist_cw = x2 - x1;
        dist_ccw = n - x2 + x1;
    } else {
        dist_cw = n - x1 + x2;
        dist_ccw = x1 - x2;
    }
    // cout << dist_cw << ' ' << dist_ccw << '\n';
    if (n <= 3) {
        cout << 1 << '\n';
    } else {
        cout << min(dist_cw, dist_ccw) + k << '\n';
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
}
