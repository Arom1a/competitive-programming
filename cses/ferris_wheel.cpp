// https://cses.fi/problemset/task/1090/
// #greedy algorithm
// lesson: don't modify the vector (or array). make the algorithm inplace (using two pointers in this problem)

#include "bits/stdc++.h"

using namespace std;

int main() {
    int n, x;
    cin >> n >> x;
    vector<int> w;
    for (int i = 0; i < n; i++) {
        int p;
        cin >> p;
        w.push_back(p);
    }

    sort(w.begin(), w.end());

    int i = 0;
    int j = w.size() - 1;
    int ans = 0;
    while (i < j) {
        if (w[i] + w[j] > x) {
            j -= 1;
        } else {
            i += 1;
            j -= 1;
        }

        ans++;
    }
    if (i == j) ans++;

    cout << ans << endl;
}
