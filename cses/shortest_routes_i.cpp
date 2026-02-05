// dijkstra

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
    int n, m;
    cin >> n >> m;
    vec<vec<pair<int, ll>>> adj(n + 1);
    for (int i = 0; i < m; i++) {
        int a, b;
        ll c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
    }
    priority_queue<pair<ll, int>, vec<pair<ll, int>>, greater<pair<ll, int>>> pq;
    vll dist(n + 1, LONG_LONG_MAX);

    dist[1] = 0;
    pq.push({0, 1});

    while (!pq.empty()) {
        auto top = pq.top();
        pq.pop();

        ll d = top.first;
        int u = top.second;

        if (d > dist[u]) continue;

        for (auto& p : adj[u]) {
            int v = p.first;
            ll weight = p.second;
            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }

    for (int i = 1; i < n; i++) {
        cout << dist[i] << ' ';
    }
    cout << dist[n] << '\n';
}

int main() {
    fio;
    int T = 1;
    while (T--) {
        solve();
    }
}
