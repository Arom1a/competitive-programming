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
using vs = vec<string>;
using vvs = vec<vs>;
template <typename T>
using max_heap = priority_queue<T>;
template <typename T>
using min_heap = priority_queue<T, vector<T>, greater<T>>;

void solve() {
    int n, k;
    cin >> n >> k;
    vi as(n);
    int p;
    for (int i = 0; i < n; i++) {
        cin >> as[i];
    }
    cin >> p;
    p -= 1;

    if (n == 1) {
        cout << 0 << '\n';
        return;
    }

    int target = as[p];

    int l = 0, r = n - 1;
    while (l < p && as[l] == target) {
        l += 1;
    }
    while (r > p && as[r] == target) {
        r -= 1;
    }

    int lcnt = 0, rcnt = 0;
    for (; l < p; l++) {
        if (as[l] != as[l + 1]) {
            lcnt += 1;
        }
    }
    for (; r > p; r--) {
        if (as[r] != as[r - 1]) {
            rcnt += 1;
        }
    }

    int ans = max(lcnt, rcnt);
    if (ans % 2 == 1) ans += 1;

    cout << ans << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
}
