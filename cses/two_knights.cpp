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
    cin >> n;

    for (ll i = 1; i <= n; i++) {
        ll ans = (i * i) * (i * i - 1) / 2 - (i - 2) * (i - 1) * 2 * 2 * (i > 2);
        cout << ans << '\n';
    }
}
