#include "bits/stdc++.h"

typedef long long ll;
using namespace std;

template <typename T>
void print_vector(const vector<T>& my_vec) {
    for (const T& i : my_vec)
        cout << i << ' ';
    cout << endl;
}

int MAX_N = 1e5 + 1;
int N, M;
vector<int> p(MAX_N);
vector<vector<pair<ll, ll>>> adj(MAX_N);
vector<pair<ll, ll>> swap_list(MAX_N);  // first is original, second is where should be

void find_all_path_util(int u, int d, vector<bool>& visited, vector<int>& path, int& path_index,
                        vector<int>& mins) {
    visited[u] = true;
    path[path_index] = u;
    path_index++;

    if (u == d) {
        for (int i = 0; i < path_index; i++)
            cout << path[i] << ' ';
        cout << endl;
    } else {
        vector<int>::iterator i;
        for (i = adj[u].begin(); i != adj[u].end(); i++)
            if (!visited[*i])
                find_all_path_util(*i, d, visited, path, path_index)
    }
    path_index--;
    visited[u] = false;
}

void find_all_path(int s, int d) {
    vector<bool> visited(MAX_N);
    vector<int> path(MAX_N);
    vector<ll> path_w(MAX_N);
}

void find_all_path(int s, int d) {
    vector<bool> visited(MAX_N);
    vector<int> path(MAX_N);
    vectro<ll> ws(MAX_N);
    int path_index = 0;
    vector<int> mins;

    find_all_path_util(s, d, visited, path, path_index, mins);
}

int main() {
    // input
    cin >> N >> M;
    for (int i = 0; i < N; i++)
        cin >> p[i];
    for (int i = 0; i < M; i++) {
        int a, b;
        ll w;
        cin >> a >> b >> w;
        adj[a].push_back(make_pair(b, w));
        adj[b].push_back(make_pair(a, w));
    }

    // test
    // int N = ;
    // vector<int> c{};
    // expected:

    // answer below
    int ans = 0;

    for (int i = 0; i < N; i++) {
        if (i + 1 != p[i])
            swap_list[i] = make_pair(p[i], i + 1);
    }

    // for (auto i : swap_list)                             // debug
    //     if (i != pair<ll, ll>(0, 0))                     // debug
    //         cout << " | " << i.first << ' ' << i.second; // debug
    // cout << " | \n";                                     // debug

    for ()

        cout << ans << '\n';
}
