#include <bits/stdc++.h>

using namespace std;
#define all(a) a.begin(), a.end()
#define fio                  \
    ios::sync_with_stdio(0); \
    cin.tie(NULL)
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vll;

void solve() {
    int n;
    cin >> n;
    vll ds(n);
    for (int i = 0; i < n; i++)
        cin >> ds[i];

    sort(all(ds));
    ll ans = 0;
    ll cargo = accumulate(all(ds), 0LL);
    for (ll& d : ds) {
        ans += cargo * d;
        cargo -= d;
        ans += cargo * d;
    }
    cout << ans << '\n';
}

int main() {
    fio;
    int T = 1;
    while (T--) {
        solve();
    }
}
