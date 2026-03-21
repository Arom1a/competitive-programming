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
    ll n, c, k;
    cin >> n >> c >> k;
    vll ai(n);
    for (auto& i : ai) {
        cin >> i;
    }
    sort(all(ai));
    int i = 0;
    while (i < n && ai[i] <= c) {
        ll flip = min(c - ai[i], k);
        k -= flip;
        c += ai[i] + flip;
        i += 1;
    }
    cout << c << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
}
