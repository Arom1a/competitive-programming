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
    ll ans = 0;
    ll last, next;
    cin >> last;
    for (int i = 1; i < n; i++) {
        cin >> next;
        if (next < last) {
            ans += last - next;
            continue;
        }
        last = next;
    }

    cout << ans << '\n';
}
