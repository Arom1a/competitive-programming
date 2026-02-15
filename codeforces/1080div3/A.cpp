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
    vi as(n);
    bool flag = false;
    for (int i = 0; i < n; i++) {
        cin >> as[i];
        if (as[i] == 67) flag = true;
    }

    if (flag) cout << "YES\n";
    else cout << "NO\n";
}

int main() {
    fio;
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
}
