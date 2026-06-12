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

void solve() {
    int n;
    cin >> n;
    vi as(n);
    for (int i = 0; i < n; i++) {
        cin >> as[i];
    }

    vec<vec<pair<int, int>>> good_segs(n / 2 + 1);
    vi visited(n + 1, -1);

    for (int i = 0; i < n; i++) {
        int min_val = as[i];
        int max_val = as[i];
        for (int j = i; j < n; j++) {
            if (visited[as[j]] == i) {
                break;
            }
            visited[as[j]] = i;
            min_val = min(min_val, as[j]);
            max_val = max(max_val, as[j]);

            if (max_val - min_val == j - i) {
                int k = j - i + 1;
                if (k <= n / 2) {
                    good_segs[k].push_back({min_val, i});
                }
            }
        }
    }

    vi min_idx(n + 1, n + 1);
    vi max_idx(n + 1, -1);

    for (int k = n / 2; k >= 1; k--) {
        if (good_segs[k].empty()) continue;

        for (const auto& p : good_segs[k]) {
            int x = p.first;
            int i = p.second;
            min_idx[x] = min(min_idx[x], i);
            max_idx[x] = max(max_idx[x], i);
        }

        bool found = false;
        for (const auto& p : good_segs[k]) {
            int x = p.first;
            if (x + k <= n && min_idx[x + k] <= n) {
                if (max_idx[x + k] - min_idx[x] >= k || max_idx[x] - min_idx[x + k] >= k) {
                    found = true;
                    break;
                }
            }
        }
        if (found) {
            cout << k << "\n";
            return;
        }

        for (const auto& p : good_segs[k]) {
            int x = p.first;
            min_idx[x] = n + 1;
            max_idx[x] = -1;
        }
    }

    cout << 0 << "\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
}
