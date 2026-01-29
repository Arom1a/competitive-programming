#include <bits/stdc++.h>

using namespace std;
#define all(a) a.begin(), a.end()
#define fio                  \
    ios::sync_with_stdio(0); \
    cin.tie(NULL)
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vll;

ll leq(ll num, ll n) {
    ll sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += min(n, num / i);
    }
    return sum;
}

void solve() {
    ll n;
    cin >> n;

    ll lo = 1, hi = n * n, m;

    while (lo < hi) {
        m = (lo + hi) / 2;
        if (leq(m, n) >= (n * n + 1) / 2) {
            hi = m;
        } else {
            lo = m + 1;
        }
    }
    cout << hi << '\n';
}

int main() {
    fio;

    int T = 1;
    while (T--) {
        solve();
    }
}
