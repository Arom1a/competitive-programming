// https://cses.fi/problemset/task/1192/
// #graph
// lesson: in a graph where u can go up, right, down, and left, u can surround it with walls of 0s for eazy edge handling

#include <utility>
#include "bits/stdc++.h"

using namespace std;
#define all(a) a.begin(), a.end()
#define fio                  \
    ios::sync_with_stdio(0); \
    cin.tie(NULL)
#define f first
#define s second
#define mp make_pair
typedef long long ll;
typedef vector<int> vi;

template <typename T>
void print_1dvec(const vector<T> &vec) {
    for (const T &i : vec)
        cout << i << '\n';
    // cout << '\n';
}

template <typename T>
void print_2dvec(const vector<vector<T>> &vec) {
    for (const vector<T> &i : vec) {
        for (const T &j : i) {
            cout << j << ' ';
        }
        cout << '\n';
    }
}

pair<int, int> DIR[] = {mp(0, -1), mp(1, 0), mp(0, 1), mp(-1, 0)};  //up right down left

bool dfs(int i, int j, const vector<string> &map, vector<vector<bool>> &visited,
         vector<vector<bool>> &local_visited) {
    if (map[i][j] == '#') return 0;
    if (visited[i][j]) return 0;
    if (local_visited[i][j]) return 0;
    visited[i][j] = 1;
    local_visited[i][j] = 1;
    for (int k = 0; k < 4; k++) {
        dfs(i + DIR[k].f, j + DIR[k].s, map, visited, local_visited);
    }
    local_visited[i][j] = 0;
    return 1;
}

int main() {
    fio;

    int n, m;
    cin >> n >> m;
    vector<string> map(n + 2);
    for (int i = 0; i < m + 2; i++) {
        map.front() += '#';
        map.back() += '#';
    }
    for (int i = 1; i <= n; i++) {
        string tmp;
        cin >> tmp;
        tmp = '#' + tmp + '#';
        map[i] = tmp;
    }
    vector<vector<bool>> visited(n + 2, vector<bool>(m + 2));
    vector<vector<bool>> local_visited(n + 2, vector<bool>(m + 2));

    int ans = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (dfs(i, j, map, visited, local_visited)) ans++;
        }
    }

    cout << ans << '\n';
}
