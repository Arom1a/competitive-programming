// https://cses.fi/problemset/task/1668
#include "bits/stdc++.h"

using namespace std;

const int MAX_N = 1e5 + 1;
array<vector<int>, MAX_N> f_adj;
vector<int> group_list(MAX_N);
bool condition = true;

void dfs(int node, int group) {
    if (group_list[node] != 0)
        return;
    group_list[node] = group;
    int next_group = group % 2 + 1;
    for (int child : f_adj[node]) {
        // cout << child << '\n';  // debug
        if (group_list[child] == group) {
            condition = false;
            return;
        }
        if (group_list[child] == 0)
            dfs(child, next_group);
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        f_adj[a].push_back(b);
        f_adj[b].push_back(a);
    }

    // cout << "executed" << '\n';  // debug

    for (int i = 1; i <= n && condition; i++) {
        dfs(i, 1);
    }

    if (!condition) {
        cout << "IMPOSSIBLE" << '\n';
    } else {
        cout << group_list[1];
        for (int i = 2; i <= n; i++) {
            cout << ' ' << group_list[i];
        }
        cout << '\n';
    }
}
