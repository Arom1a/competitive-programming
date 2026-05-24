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
    vvi b(n, vi(n));
    unordered_map<int, int> bm;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int c;
            cin >> c;
            bm[c] += 1;
        }
    }
    for (auto& i : bm) {
        if (i.second > n * n - n) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}

int main() {
    fio;
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
}
