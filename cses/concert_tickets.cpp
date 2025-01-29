// https://cses.fi/problemset/task/1091
// #multiset
// lesson: learn how to use multiset

#include "bits/stdc++.h"

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    multiset<int> t;

    for (int i = 0; i < n; i++) {
        int h_i;
        cin >> h_i;
        t.insert(h_i);
    }

    for (int i = 0; i < m; i++) {
        int t_i;
        cin >> t_i;
        auto it = t.upper_bound(t_i);
        if (it == t.begin()) {
            cout << -1 << '\n';
            continue;
        }

        it = prev(it);

        cout << *it << '\n';
        t.erase(it);
    }
}
