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
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    for (int i = 0; i < n; ++i) {
        if (s[i] == '1') {
            if (i + k < n) {
                s[i] = (s[i] == '0') ? '1' : '0';
                s[i + k] = (s[i + k] == '0') ? '1' : '0';
            } else {
                cout << "NO\n";
                return;
            }
        }
    }
    cout << "YES\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
}
