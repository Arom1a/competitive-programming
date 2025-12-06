#include "bits/stdc++.h"

using namespace std;
#define all(a) a.begin(), a.end()
#define fio                  \
    ios::sync_with_stdio(0); \
    cin.tie(NULL)
#define f first
#define s second
#define mp make_pair
typedef long long ll;
typedef vector<int> vi;

int main() {
    fio;
    int n;
    cin >> n;

    vector<ll> pfs;
    ll sum = 0;
    while (n--) {
        ll x;
        cin >> x;
        sum += x;
        pfs.push_back(sum);
    }

    ll ans = pfs[0];
    ll min_seen = 0;
    for (auto i : pfs) {
        ans = max(ans, i - min_seen);
        min_seen = min(min_seen, i);
    }
    cout << ans << '\n';
}
