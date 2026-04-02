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
    int t;
    double s, max_size;
    cin >> t >> s;
    if (t == 1) {
        max_size = 2 * s;
    } else if (t == 2) {
        max_size = sqrt(2) * s;
    } else {
        max_size = s;
    }
    int N;
    cin >> N;

    int ans = 0;
    for (int i = 0; i < N; i++) {
        int shape;
        double size;
        cin >> shape >> size;
        if (shape == 1) {
            size *= 2;
        } else if (shape == 3) {
            size = size * 3 / 2 / sqrt(3);
        }

        if (size <= max_size) {
            ans += 1;
        }
    }
    cout << ans << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int T = 1;
    while (T--) {
        solve();
    }
}
