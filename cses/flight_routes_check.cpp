// https://cses.fi/problemset/submit/1682/
// #directed graph, #SCC, #strongly connected components
// lesson: using the reverse of a directed graph could be helpful

#include "bits/stdc++.h"

using namespace std;

void dfs(const vector<vector<int>> &adj, int n, bool visited[], bool can_reach[]) {
    if (visited[n]) return;

    visited[n] = 1;
    can_reach[n] = 1;
    for (int i : adj[n]) {
        dfs(adj, i, visited, can_reach);
    }
    // visited[n] = 0;  // comment out since useless, don't need to go deeper
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    vector<vector<int>> adj_r(n + 1);  // adj_reversed
    for (int i = 1; i <= m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj_r[b].push_back(a);
    }

    bool v[n + 1], r[n + 1], r_r[n + 1];  // visited, can_reach, can_reach_reversed
    for (int i = 0; i <= n; i++) {
        v[i] = 0;
        r[i] = 0;
        r_r[i] = 0;
    }

    dfs(adj, 1, v, r);
    for (int j = 1; j <= n; j++) {
        if (!r[j]) {
            cout << "NO\n" << 1 << ' ' << j << '\n';
            return 0;
        }
    }
    memset(v, 0, sizeof(v));
    dfs(adj_r, 1, v, r_r);
    for (int j = 1; j <= n; j++) {
        if (!r_r[j]) {
            cout << "NO\n" << j << ' ' << 1 << '\n';
            return 0;
        }
    }

    cout << "YES\n";
}
