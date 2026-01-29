#include <bits/stdc++.h>

using namespace std;
#define all(a) a.begin(), a.end()
#define fio                  \
    ios::sync_with_stdio(0); \
    cin.tie(NULL)
template <typename T>
using vec = vector<T>;
typedef long long ll;
typedef vec<int> vi;
typedef vec<vec<int>> vvi;
typedef vec<ll> vll;
typedef vec<vec<ll>> vvll;
typedef vec<bool> vb;
typedef vec<vec<bool>> vvb;
typedef vec<string> vs;
typedef vec<vec<string>> vvs;

template <typename T>
void print_1dvec(const vector<T>& vec) {
    for (const T& i : vec)
        cout << i << ' ';
    cout << '\n';
}

void solve() {
    int n;
    cin >> n;

    vi ans;
    vb used(n + 1, false);
    ans.push_back(1);
    used[1] = 1;
    int last = 1;
    for (int i = n - 1; i >= 1; i--) {
        last += i;
        if (last > n || used[last]) {
            last -= 2 * i;
        }
        if (last <= 0 || used[last]) {
            exit(1);
        }

        used[last] = 1;
        ans.push_back(last);
    }

    reverse(all(ans));
    print_1dvec(ans);
}

int main() {
    fio;
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
}
