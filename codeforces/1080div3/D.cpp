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
    vll fs(n);
    for (int i = 0; i < n; i++) {
        cin >> fs[i];
    }

    ll all_ones = (fs[0] + fs[n - 1]) / (n - 1);
    vll ds(n);
    for (int i = 0; i < n - 1; i++) {
        ds[i] = fs[i + 1] - fs[i];
    }
    ds[n - 1] = all_ones;
    ll sum = 0;
    vll ans(n);
    for (int i = 0; i < n; i++) {
        ans[i] = (ds[i] + all_ones) / 2 - sum;
        sum += ans[i];
    }

    for (auto& i : ans) {
        cout << i << ' ';
    }
    cout << '\n';
}

int main() {
    fio;
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
}
