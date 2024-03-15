// https://cses.fi/problemset/task/1666
// graph traversal

#include "bits/stdc++.h"

typedef long long ll;
using namespace std;

int MAX_N = 1e5 + 1;

template <typename T>
void print_vector(const vector<T>& my_vec) {
    for (const T& i : my_vec)
        cout << i << ' ';
    cout << endl;
}

int n, m;
vector<vector<int>> adj(MAX_N);
vector<bool> visited(MAX_N, false);
vector<int> ans_bridges;

void dfs(int node) {
    if (visited[node] == true)
        return;
    visited[node] = true;
    for (const int& child : adj[node])
        dfs(child);
}

int main() {
    // input
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        // cout << "executed" << '\n'; // debug
        // cout << adj.size() << '\n'; // debug
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    // test
    // int n = ;
    // vector<int> c{};
    // expected:

    // answer below
    for (int i = 1; i <= n; i++) {
        if (visited[i] == true)
            continue;
        ans_bridges.push_back(i);
        dfs(i);
    }

    cout << ans_bridges.size() - 1 << '\n';
    for (int i = 0; i < ans_bridges.size() - 1; i++)
        cout << ans_bridges[i] << ' ' << ans_bridges[i + 1] << '\n';
}
