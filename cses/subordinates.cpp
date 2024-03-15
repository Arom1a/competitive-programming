// https://cses.fi/problemset/task/1674
// tree, dynamic programming

#include "bits/stdc++.h"
using namespace std;

int MAX_N = 2e5 + 1;
vector<vector<int>> adj(MAX_N);
vector<int> ans(MAX_N);

void dfs(int node, int parent) {
    ans[node] = 1;
    for (auto child : adj[node])
        if (child != parent) {
            dfs(child, node);
            ans[node] += ans[child];
        }
}

int main() {
    int n;
    cin >> n;
    vector<int> c(n - 1);
    for (int i = 2; i <= n; i++) {
        int tmp;
        cin >> tmp;
        adj[tmp].push_back(i);
    }
    dfs(1, 0);
    for (int i = 1; i <= n; i++) {
        cout << ans[i] - 1 << " \n"[i == n];
    }
}
