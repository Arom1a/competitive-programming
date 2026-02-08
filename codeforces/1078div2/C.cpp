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

void solve() {
    int n, k;
    cin >> n >> k;
    vs ss(k);
    for (int i = 0; i < k; i++) {
        cin >> ss[i];
    }

    vi col_masks(n, 0);
    for (int j = 0; j < n; j++) {
        for (int i = 0; i < k; i++) {
            int char_bit = (ss[i][j] - 'a');
            col_masks[j] |= (1 << char_bit);
        }
    }

    for (int len = 1; len <= n; len++) {
        if (n % len != 0) continue;

        string result = "";
        bool possible = true;

        for (int i = 0; i < len; i++) {
            int current_intersection = col_masks[i];

            for (int j = i + len; j < n; j += len) {
                current_intersection &= col_masks[j];
            }

            if (current_intersection == 0) {
                possible = false;
                break;
            }

            int char_idx = __builtin_ctz(current_intersection);
            result += (char)('a' + char_idx);
        }

        if (possible) {
            string ans = "";
            for (int i = 0; i < n / len; i++) {
                ans += result;
            }
            cout << ans << "\n";
            return;
        }
    }
}

int main() {
    fio;
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
}
