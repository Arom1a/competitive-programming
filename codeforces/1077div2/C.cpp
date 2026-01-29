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

bool test(int k, int n, const vi& a, const vi& b) {
    int min_val = b.front();
    int max_val = b.back();

    if (max_val - min_val < k) {
        return false;
    }

    for (int i = 0; i < n; i++) {
        bool can_swap_with_min = (a[i] - min_val >= k);
        bool can_swap_with_max = (max_val - a[i] >= k);

        if (!can_swap_with_min && !can_swap_with_max) {
            if (a[i] != b[i]) {
                return false;
            }
        }
    }

    return true;
}

void solve() {
    int n;
    cin >> n;
    vi as(n);
    for (int i = 0; i < n; i++) {
        cin >> as[i];
    }
    vi sort_as(all(as));
    sort(all(sort_as));

    bool sorted = true;
    for (int i = 0; i < n; i++) {
        if (as[i] != sort_as[i]) {
            sorted = false;
            break;
        }
    }
    if (sorted) {
        cout << -1 << '\n';
        return;
    }

    int lo, hi, m;
    lo = 0;
    hi = 1e9 + 1;

    while (lo + 1 < hi) {
        m = lo + (hi - lo) / 2;
        if (test(m, n, as, sort_as)) lo = m;
        else hi = m;
    }
    cout << hi - 1 << '\n';
}

int main() {
    fio;
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
}
