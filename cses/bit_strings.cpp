// https://cses.fi/problemset/task/1617

#include "bits/stdc++.h"

typedef long long ll;
using namespace std;

int main() {
    ll n;
    cin >> n;
    ll ans = 1;
    while (n--) ans = ans * 2 % (ll)(1e9 + 7);
    cout << ans << endl;
}
