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

void solve(vvi& jumping) {
    int x, k;
    cin >> x >> k;
    x--;
    for (int i = 0; i < 30; i++) {
        if (k & (1 << i)) {
            x = jumping[i][x];
        }
    }
    cout << x + 1 << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, q;
    cin >> n >> q;
    vvi jumping(1, vi(n));
    for (int i = 0; i < n; i++) {
        cin >> jumping[0][i];
        jumping[0][i]--;
    }

    for (int i = 1; i < 30; i++) {
        vi next = vi(n);
        for (int j = 0; j < n; j++) {
            next[j] = jumping[i - 1][jumping[i - 1][j]];
        }
        jumping.push_back(next);
    }

    while (q--) {
        solve(jumping);
    }
}
