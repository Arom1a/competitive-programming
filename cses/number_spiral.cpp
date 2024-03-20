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
    int t;
    cin >> t;
    while (t--) {
        ll y, x;
        cin >> y >> x;
        ll max_num = max(x, y);
        ll diag = max_num * max_num - max_num + 1;
        int sign1 = (max_num % 2) ? -1 : 1;
        ll ans = diag + sign1 * (y - x);
        cout << ans << '\n';
    }
}
