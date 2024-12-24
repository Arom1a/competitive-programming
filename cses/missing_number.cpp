// https://cses.fi/problemset/task/1083

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
    vector<bool> have(n);
    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        have[tmp - 1] = 1;
    }

    // answer below
    int ans = find(have.begin(), have.end(), 0) - have.begin() + 1;

    cout << ans << '\n';
}
