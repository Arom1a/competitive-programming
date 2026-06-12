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
using vc = vec<char>;
using vvc = vec<vc>;
using vs = vec<string>;
using vvs = vec<vs>;
template <typename T>
using max_heap = priority_queue<T>;
template <typename T>
using min_heap = priority_queue<T, vector<T>, greater<T>>;

template <typename T>
void print_1dvec(const vector<T>& vec) {
    for (const T& i : vec)
        cout << i << ' ';
    cout << '\n';
}

void solve() {
    int a, b, x;
    cin >> a >> b >> x;

    vi pa, pb;
    pa.push_back(a);
    while (a != 1 && a != 0) {
        a /= x;
        pa.push_back(a);
    }
    pb.push_back(b);
    while (b != 1 && b != 0) {
        b /= x;
        pb.push_back(b);
    }

    // print_1dvec(pa);
    // print_1dvec(pb);

    int ans = INT_MAX;
    for (int i = 0; i < pa.size(); i++) {
        for (int j = 0; j < pb.size(); j++) {
            ans = min(ans, i + j + abs(pa[i] - pb[j]));
        }
    }

    cout << ans << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
}
