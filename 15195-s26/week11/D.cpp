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

const int MAXN = 100005;
vector<int> adj[MAXN];
bool matched[MAXN];
vector<pair<int, int>> ans;

void dfs(int u, int parent) {
    for (int v : adj[u]) {
        if (v != parent) {
            dfs(v, u);
        }
    }

    if (parent != 0 && !matched[u] && !matched[parent]) {
        matched[u] = true;
        matched[parent] = true;
        ans.push_back({u, parent});
    }
}

void solve() {
    int N, M;
    cin >> N >> M;

    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1, 0);

    cout << ans.size() << "\n";
    for (auto edge : ans) {
        cout << edge.first << " " << edge.second << "\n";
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int T = 1;
    while (T--) {
        solve();
    }
}
