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

int count_bit(int x) {
    int ans = 0;
    for (int i = 0; i < 31; i++) {
        ans += (x >> i) & 1;
    }
    return ans;
}

int best_num(int target, int mask) {
    vi candidates;

    int current_val = 0;

    for (int i = 30; i >= 0; i--) {
        int bit_mask = (mask >> i) & 1;
        int bit_target = (target >> i) & 1;

        if (bit_mask == 0) {
            if (bit_target == 1) {
                int floor_candidate = current_val | (mask & ((1 << i) - 1));
                candidates.push_back(floor_candidate);
                goto find_best;
            } else {
            }
        } else {
            if (bit_target == 0) {
                int ceil_candidate = current_val | (1 << i);
                candidates.push_back(ceil_candidate);
            } else {
                int floor_candidate = current_val | (mask & ((1 << i) - 1));
                candidates.push_back(floor_candidate);
                current_val |= (1 << i);
            }
        }
    }
    candidates.push_back(current_val);

find_best:
    if (candidates.empty()) return -1;

    int best_num = candidates[0];
    int min_diff = abs(target - best_num);

    for (size_t i = 1; i < candidates.size(); ++i) {
        // cout << "    " << candidates[i] << '\n';
        int diff = abs(target - candidates[i]);
        if (diff < min_diff) {
            min_diff = diff;
            best_num = candidates[i];
        } else if (diff == min_diff) {
            // Tie-breaker: prefer smaller number
            best_num = min(best_num, candidates[i]);
        }
    }

    return best_num;
}

void solve() {
    int x, y;
    cin >> x >> y;

    int xbit = count_bit(x);
    int ybit = count_bit(y);

    // cout << xbit << ' ' << ybit << '\n';

    int p, q;
    if (xbit <= ybit) {
        p = x;
        unsigned int possi = ~p;
        q = best_num(y, possi);
    } else {
        q = y;
        unsigned int possi = ~q;
        p = best_num(x, possi);
    }

    cout << p << ' ' << q << '\n';
}

int main() {
    fio;
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
}
