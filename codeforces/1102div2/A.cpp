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
    vi bs(n);
    for (int i = 0; i < n; i++) {
        cin >> bs[i];
    }

    sort(all(bs));

    int x = bs[n - 1];
    int y = bs[n - 2];
    for (int i = n - 3; i >= 0; i--) {
        int tmp = bs[i];
        if (x % y != tmp) {
            cout << -1 << '\n';
            return;
        }
        x = y;
        y = tmp;
    }
    cout << bs[n - 1] << ' ' << bs[n - 2] << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
}
