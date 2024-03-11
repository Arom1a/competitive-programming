#include "bits/stdc++.h"

typedef long long ll;
using namespace std;

template <typename T>
void print_vector(const vector<T> &my_vec) {
    for (const T &i : my_vec)
        cout << i << ' ';
    cout << endl;
}

int main() {
    // input
    int n;
    cin >> n;
    vector<ll> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }

    // test
    // int n = ;
    // vector<int> c{};
    // expected:

    // answer below
    ll ans = 0;
    sort(p.begin(), p.end());
        ll mid = p[n / 2];
        for (const ll &i : p) {
            ans += abs(i - mid);
        }
    // cout << mid << '\n';  // debug
    cout << ans << '\n';
}
