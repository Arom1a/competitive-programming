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
    int n, k;
    cin >> n >> k;
    vi as(n);
    for (int i = 0; i < n; i++) {
        cin >> as[i];
    }

    sort(all(as));
    reverse(all(as));

    int last = as[0];
    int cnt = 1;
    vi cnts;
    for (int i = 1; i < as.size(); i++) {
        if (as[i] == last) {
            cnt += 1;
            continue;
        } else {
            if (last - as[i] > k) {
                cnts.push_back(cnt);
                cnt = 1;
                last = as[i];
            } else {
                cnts.push_back(cnt);
                cnt += 1;
            }
        }
    }

    cnts.push_back(cnt);

    for (int& cnt : cnts) {
        if (cnt % 2 == 0) {
            cout << "YES\n";
            return;
        }
    }

    cout << "NO\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
}
