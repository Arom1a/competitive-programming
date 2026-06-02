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
    string s;
    cin >> s;

    int cnt4 = 0;
    int cnt2 = 0;
    for (char& c : s) {
        if (c == '4') cnt4 += 1;
        else if (c == '2') cnt2 += 1;
    }

    int ans = cnt2;
    int cnt13 = 0;
    for (char& c : s) {
        if (c == '1' || c == '3') {
            cnt13 += 1;
        } else if (c == '2') {
            cnt2 -= 1;
        }
        ans = min(ans, cnt13 + cnt2);
    }
    cout << ans + cnt4 << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
}
