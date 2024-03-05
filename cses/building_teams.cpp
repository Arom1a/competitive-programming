// https://cses.fi/problemset/task/1668
#include "bits/stdc++.h"

typedef long long ll;
using namespace std;

template <typename T>
void print_vector(const vector<T> &my_vec) {
    for (const T &i : my_vec)
        cout << i << ' ';
    cout << endl;
}

int MAX_N = 1e5 + 1;
vector<vector<int>> f_adj(MAX_N);  // friendship
vector<bool> visited(MAX_N);
vector<int> group_list(MAX_N);
bool condition = true;

int opposite(int input) {
    if (input == 1)
        return 2;
    return 1;
}

void dfs(int node, const int ori_group_num) {
    if (visited[node] == true) {
        if (group_list[node] == ori_group_num) {
            condition = false;
            cout << "IMPOSSIBLE" << '\n';
        }
        return;
    }
    visited[node] = true;
    group_list[node] = opposite(ori_group_num);
    for (const int &child : f_adj[node])
        dfs(child, group_list[node]);
}

int main() {
    // input
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        f_adj[a].push_back(b);
        f_adj[b].push_back(a);
    }

    for (int i = 1; i <= n && condition; i++) {
        if (group_list[i] == 0) {
            group_list[i] = 1;
            for (const int &child : f_adj[i])
                dfs(child, group_list[i]);
        }
    }

    // test
    // int n = ;
    // vector<int> f_adj{};
    // expected:

    // answer below

    if (condition == true)
        for (const int &i : group_list)
            if (i != 0)
                cout << i << ' ';
}
