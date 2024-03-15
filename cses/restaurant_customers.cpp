// https://cses.fi/problemset/task/1619
// sorting and searching

#include "bits/stdc++.h"

typedef long long ll;
using namespace std;

template <typename T>
void print_vector(const vector<T>& my_vec) {
    for (const T& i : my_vec)
        cout << i << ' ';
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // input
    int n;
    cin >> n;
    vector<pair<int, int>> all;  // 1 means come, 2 means leave
    all.reserve(2 * n);
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        // all[2 * i] = make_pair(a, 1);
        // all[2 * i + 1] = make_pair(b, -1);
        all.push_back({a, 1});
        all.push_back({b, -1});
    }

    // test
    // int n = ;
    // vector<pair<int, bool>> all{{5, 1}, {8, -1}, {2, 1}, {4, -1}, {3, 1}, {9, -1}};
    // expected:

    // answer below
    int ans = 0;
    sort(all.begin(), all.end());
    // for (auto i : all) {                             // debug
    //     cout << i.first << ' ' << i.second << '\n';  // debug
    // }                                                // debug
    int counter = 0;
    for (auto i : all) {
        counter += i.second;
        ans = max(ans, counter);
    }

    cout << ans << '\n';
}
