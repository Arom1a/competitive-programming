// https://cses.fi/problemset/task/1629
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
    int n;
    // input
    cin >> n;
    vector<pair<int, int>> c(n);
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        c[i] = make_pair(a, b);
    }

    // test
    // int n = ;
    // vector<int> c{};
    // expected:

    // answer below
    int ans = 0;

    sort(c.begin(), c.end(),
         [](pair<int, int> &a, pair<int, int> &b) { return a.second < b.second; });
    int current_time = -1;
    for (int i = 0; i < n; i++) {
        if (current_time <= c[i].first) {
            current_time = c[i].second;
            ans++;
        }
    }

    cout << ans << '\n';
}
