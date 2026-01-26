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
    ll A, B, ca, cb, f;
    cin >> A >> B >> ca >> cb >> f;
    ll trade = B / cb;
    A += trade * ca;
    B %= cb;
    if (f <= A) {
        cout << 0 << '\n';
        return;
    }

    ll need_a = f - A;

    if (ca >= cb) {
        ll fill_b = cb - 1 - B;
        ll ans = need_a + fill_b;
        cout << ans << '\n';
        return;
    }

    ll amount_b = ((need_a + ca - 1) / ca) * cb - B;
    ll amount_a = (need_a + ca - 1) % ca;

    cout << amount_a + amount_b << '\n';
}

int main() {
    fio;

    int T;
    cin >> T;
    while (T--) {
        solve();
    }
}
