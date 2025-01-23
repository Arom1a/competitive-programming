// https://cses.fi/problemset/task/1633
// #dynamic programming
// lession:

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

template <typename T>
void print_1dvec(const vector<T> &vec) {
    for (const T &i : vec)
        cout << i << ' ';
    cout << '\n';
}

template <typename T>
void print_2dvec(const vector<vector<T>> &vec) {
    for (const vector<T> &i : vec) {
        for (const T &j : i) {
            cout << j << ' ';
        }
        cout << '\n';
    }
}

int main() {
    fio;

    int n;
    cin >> n;

    vector<ll> count;
    count.push_back(1);
    for (int i = 1; i <= n; i++) {
        ll s = 0;
        for (int j = 1; j <= 6; j++)
            if (i - j >= 0) s += count[i - j];

        count.push_back(s % (ll)(1e9 + 7));
    }

    ll ans = count[n];
    cout << ans << '\n';
}
