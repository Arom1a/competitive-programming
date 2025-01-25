// https://cses.fi/problemset/task/1634
// #dinamic programming
// lession: start from the beginning, not back tracing

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

    int n, x;
    cin >> n >> x;
    vector<int> c(n);
    for (int i = 0; i < n; i++)
        cin >> c[i];

    vector<int> count;
    count.push_back(0);
    for (int i = 1; i <= x; i++) {
        int val = INT_MAX;
        for (const int &j : c) {
            if (i - j < 0) continue;
            if (count[i - j] == -1) continue;
            val = min(val, count[i - j] + 1);
        }
        if (val == INT_MAX) count.push_back(-1);
        else count.push_back(val);
    }

    int ans = count[x];
    cout << ans << '\n';
}
