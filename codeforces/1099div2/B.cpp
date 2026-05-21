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
typedef vec<char> vc;
typedef vec<vec<bool>> vvb;
typedef vec<string> vs;
typedef vec<vec<string>> vvs;

void solve() {
    int n;
    cin >> n;
    vll a(n);
    for (ll& i : a) {
        cin >> i;
    }

    ll max_seen = -1;
    ll k = 1;
    bool sorted = true;

    for (int i = 0; i < n; i++) {
        if (sorted && i > 0 && a[i] < a[i - 1]) sorted = false;

        if (a[i] < max_seen) {
            k = max(k, max_seen - a[i]);
        }
        max_seen = max(max_seen, a[i]);
    }

    if (sorted) {
        cout << "YES\n";
        return;
    }

    ll prev = LONG_MIN;
    for (int i = 0; i < n; i++) {
        if (a[i] >= prev) {
            prev = a[i];
        } else if (a[i] + k >= prev) {
            prev = a[i] + k;
        } else {
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
