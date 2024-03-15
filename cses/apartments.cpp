// https://cses.fi/problemset/task/1084
// greedy algorithm

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
    int n, m;
    ll k;
    cin >> n >> m >> k;
    vector<ll> a(n), b(m);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }

    // test
    // int n = ;
    // vector<int> a{};
    // expected:

    // answer below
    int ans = 0;

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    // print_vector(a);
    // print_vector(b);

    int i = 0, j = 0;
    while (i < n && j < m) {
        // cout << "current:" << '\n';
        // cout << a[i] << ' ' << b[j] << '\n';
        ll diff = a[i] - b[j];
        if (abs(diff) <= k) {
            i++;
            j++;
            ans++;
        } else if (diff < 0) {
            i++;
        } else {
            j++;
        }
    }
    cout << ans << '\n';
}
