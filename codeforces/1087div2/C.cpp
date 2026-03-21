#include <bits/stdc++.h>

using namespace std;
#define all(a) a.begin(), a.end()
template <typename T>
using vec = vector<T>;
using ll = long long;
using vi = vec<int>;
using vvi = vec<vi>;
using vll = vec<ll>;
using vvll = vec<vll>;
using vb = vec<bool>;
using vvb = vec<vb>;
using vs = vec<string>;
using vvs = vec<vs>;
template <typename T>
using max_heap = priority_queue<T>;
template <typename T>
using min_heap = priority_queue<T, vector<T>, greater<T>>;

void solve() {
    int n;
    cin >> n;
    int p;

    cout << "? " << 1 << ' ' << 2 << '\n';
    cout.flush();
    cin >> p;
    if (p == 1) {
        cout << "! " << 1 << '\n';
        cout.flush();
        return;
    } else if (p == 0) {
    } else {
        exit(EXIT_FAILURE);
    }

    cout << "? " << 1 << ' ' << 3 << '\n';
    cout.flush();
    cin >> p;
    if (p == 1) {
        cout << "! " << 1 << '\n';
        cout.flush();
        return;
    } else if (p == 0) {
    } else {
        exit(EXIT_FAILURE);
    }

    cout << "? " << 2 << ' ' << 3 << '\n';
    cout.flush();
    cin >> p;
    if (p == 1) {
        cout << "! " << 2 << '\n';
        cout.flush();
        return;
    } else if (p == 0) {
    } else {
        exit(EXIT_FAILURE);
    }

    for (int q = 2; q < n; q++) {
        cout << "? " << 2 * q << ' ' << 2 * q + 1 << '\n';
        cout.flush();
        cin >> p;
        if (p == 1) {
            cout << "! " << 2 * q << '\n';
            cout.flush();
            return;
        } else if (p == 0) {
        } else {
            exit(EXIT_FAILURE);
        }
    }

    cout << "! " << 2 * n << '\n';
    cout.flush();
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
}
