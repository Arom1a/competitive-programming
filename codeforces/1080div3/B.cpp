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
    int n;
    cin >> n;

    vi a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    unordered_map<int, vi> pos, val;

    // Group by odd part
    for (int i = 1; i <= n; i++) {
        int x = i;
        while (x % 2 == 0)
            x /= 2;  // odd part

        pos[x].push_back(i);
        val[x].push_back(a[i]);
    }

    bool ok = true;

    for (auto& [k, p] : pos) {
        auto& v = val[k];

        sort(p.begin(), p.end());
        sort(v.begin(), v.end());

        if (p != v) {
            ok = false;
            break;
        }
    }

    cout << (ok ? "YES\n" : "NO\n");
}

int main() {
    fio;
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
}
