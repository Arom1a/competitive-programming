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
    ll n;
    cin >> n;
    vi cs(n);
    for (ll i = 0; i < n; i++)
        cin >> cs[i];

    ll sum = accumulate(all(cs), 0LL);
    ll ones = 0;
    ll slots = 0;
    for (int i = 0; i < n; i++) {
        if (cs[i] == 1) ones += 1;
        else slots += cs[i] / 2 - 1;
    }
    if (ones == n - 1) slots += 1;
    ll cannot_fit = max(0LL, ones - slots);
    if ((sum - cannot_fit) < 3) cout << 0 << '\n';
    else cout << sum - cannot_fit << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
}
