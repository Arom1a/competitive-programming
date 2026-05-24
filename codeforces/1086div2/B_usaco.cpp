#include <bits/stdc++.h>
using namespace std;

template <class T>
using V = vector<T>;
#define all(x) begin(x), end(x)

using ll = long long;

void solve() {
    int n, k, p, m;
    cin >> n >> k >> p >> m;

    int N = n, H = k;

    using P = pair<int, int>;
    V<P> A(N);
    for (auto& c : A)
        cin >> c.second;

    A.at(p - 1).first = -1;

    priority_queue<P, V<P>, greater<P>> pq;

    for (int i = 0; i < H - 1; ++i)
        pq.push(A.at(i));
    V<ll> cycle;  // time each win-condition in cycle is played
    ll cycle_len = 0;
    for (int i = 0; i <= N - H; ++i) {
        pq.push(A.at(i + H - 1));
        cycle_len += pq.top().second;
        if (pq.top().first == -1) cycle.push_back(cycle_len);
        pq.pop();
    }
    ll t = m;
    ll ans = t / cycle_len * size(cycle);
    ans += upper_bound(begin(cycle), end(cycle), t % cycle_len) - begin(cycle);
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
}
