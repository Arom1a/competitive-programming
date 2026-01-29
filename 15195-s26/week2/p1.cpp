#include <bits/stdc++.h>

using namespace std;
#define all(a) a.begin(), a.end()
#define fio                  \
    ios::sync_with_stdio(0); \
    cin.tie(NULL)
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vll;

bool test(ll time, vll& ks, ll t) {
    ll sum = 0;
    for (ll k : ks) {
        sum += time / k;
    }

    return sum < t;
}

void solve() {
    int n;
    ll t;
    cin >> n >> t;
    vll ks(n);
    for (int i = 0; i < n; i++) {
        cin >> ks[i];
    }
    ll fastest = *min_element(all(ks));
    ll max_t = t * fastest;

    ll lo, hi, m;
    lo = 0;
    hi = max_t;

    while (lo + 1 < hi) {
        m = lo + (hi - lo) / 2;
        if (test(m, ks, t)) lo = m;
        else hi = m;
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
