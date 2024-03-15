// https://cses.fi/problemset/task/1630
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
    int n;
    cin >> n;
    vector<pair<int, int>> t(n);
    for (auto &[a, d] : t)
        cin >> a >> d;

    // test
    // int n = ;
    // vector<int> c{};
    // expected:

    // answer below
    ll ans = 0;
    ll c = 0;  // current
    sort(t.begin(), t.end());
    for (auto &[a, d] : t) {
        ans += d - (c + a);
        c += a;
    }

    cout << ans << '\n';
}
