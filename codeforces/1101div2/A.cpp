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
    sort(all(as));

    vi cnt;
    int last = as[0];
    cnt.push_back(1);
    for (int i = 1; i < n; i++) {
        if (as[i] != last) {
            cnt.push_back(1);
            last = as[i];
        } else {
            cnt.back() += 1;
        }
    }

    int suml = 0;
    int sumr = accumulate(all(cnt), 0) - cnt[0];
    int ans = sumr;
    for (int i = 0; i < (int)cnt.size() - 1; i++) {
        int tmp = max(suml, sumr);
        ans = min(ans, tmp);

        suml += cnt[i];
        sumr -= cnt[i + 1];
    }
    ans = min(ans, suml);

    cout << ans << endl;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
}
