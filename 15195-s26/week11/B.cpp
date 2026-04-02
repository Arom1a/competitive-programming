// "hello :3" from BigInt in python :(

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

static ll asdf[51][1000];

ll calc(int n, int sum) {
    if (sum < 0) {
        return 0;
    }
    if (asdf[n][sum] != -1) {
        return asdf[n][sum];
    }
    if (n == 1) {
        return 0 <= sum && sum <= 9;
    }

    ll ans = 0;
    for (int i = 0; i <= 9; i++) {
        ans += calc(n - 1, sum - i);
    }

    asdf[n][sum] = ans;
    return ans;
}

void solve() {
    int N, S;
    cin >> N >> S;
    if (S % 2 == 1) {
        cout << 0 << '\n';
        return;
    }
    int half = S / 2;

    for (auto& i : asdf) {
        for (auto& j : i) {
            j = -1;
        }
    }

    ll a = calc(N, half);
    cout << a * a << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int T = 1;
    while (T--) {
        solve();
    }
}
