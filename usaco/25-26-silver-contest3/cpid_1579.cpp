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

int N;

bitset<67> get_possible(vi& coords) {
    map<int, int> counts;
    for (int x : coords)
        counts[x]++;

    vec<pair<int, int>> A(all(counts));
    int m = (int)A.size();

    vec<bitset<67>> dp(N + 1);
    dp[0].set(0);

    for (int i = 0; i < m; ++i) {
        int v = A[i].first;
        int c = A[i].second;

        int max_k = (i > 0 && v == A[i - 1].first + 1) ? A[i - 1].second : 0;

        vec<bitset<67>> new_dp(N + 1);

        for (int k = 0; k <= min(c, max_k); ++k) {
            if (dp[k].none()) continue;

            int rem = c - k;

            for (int next_k = rem % 2; next_k <= rem; next_k += 2) {
                int added_e = (rem - next_k) / 2;
                new_dp[next_k] |= (dp[k] << added_e);
            }
        }
        dp = std::move(new_dp);
    }

    return dp[0];
}

void solve() {
    cin >> N;
    vi xs(N), ys(N);
    for (int i = 0; i < N; ++i) {
        cin >> xs[i] >> ys[i];
    }
    if (N % 2 == 1) {
        cout << "NO\n";
        return;
    }

    bitset<67> poss_X = get_possible(xs);
    bitset<67> poss_Y = get_possible(ys);

    bool possible = false;
    for (int e_X = 0; e_X <= N / 2; ++e_X) {
        if (poss_X.test(e_X)) {
            int e_Y = N / 2 - e_X;
            if (e_Y >= 0 && e_Y <= N / 2 && poss_Y.test(e_Y)) {
                possible = true;
                break;
            }
        }
    }

    if (possible) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}

int main() {
    fio;
    int T;
    if (cin >> T) {
        while (T--) {
            solve();
        }
    }
}
