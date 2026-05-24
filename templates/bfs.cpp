#include <bits/stdc++.h>

using namespace std;

int bfs(vector<vector<int>> adj, int s, int e, int n) {
    queue<int> q;
    vector<bool> visited(n + 1);

    q.push(s);
    visited[s] = true;

    while (!q.empty()) {
        auto back = q.front();
        q.pop();

        for (auto& i : adj[back]) {
            if (false) continue;

            q.push(i);
        }
    }
}
