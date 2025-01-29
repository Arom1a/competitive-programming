// https://cses.fi/problemset/task/1193
// #graph, #bfs
// lesson: it turns out that bfs doesn't need a helper func but dfs need (my first time writing bfs)

#include <climits>
#include <tuple>
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
        cout << i << ' ';
    cout << '\n';
}

template <typename T>
void print_2dvec(const vector<vector<T>> &vec) {
    for (const vector<T> &i : vec) {
        for (const T &j : i) {
            if (j == INT_MAX) cout << '-' << ' ';
            else cout << j << ' ';
        }
        cout << '\n';
    }
    cout << '\n';
}

pair<int, int> DIR[] = {mp(0, -1), mp(1, 0), mp(0, 1), mp(-1, 0)};  //up right down left

pair<int, int> start(int n, int m, const vector<string> &map) {
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (map[i][j] == 'A') return mp(i, j);
    return mp(0, 0);
}

pair<int, int> end(int n, int m, const vector<string> &map) {
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (map[i][j] == 'B') return mp(i, j);
    return mp(0, 0);
}

string path(const vector<vector<int>> &map_step, int x, int y) {
    int curr_step = map_step[x][y];
    if (curr_step == 0) return "";
    string rtn = "LDRU";
    for (int i = 0; i < 4; i++) {
        int nx = x - DIR[i].f;
        int ny = y - DIR[i].s;
        if (map_step[nx][ny] == curr_step - 1) {
            // cout << nx << ' ' << ny << ' ' << (curr_step - 1) << '\n';
            return path(map_step, nx, ny) + rtn[i];
        }
    }
    return "Err";
}

string bfs(const int n, const int m, int x, int y, const vector<string> &map) {
    queue<tuple<int, int, int>> q;
    vector<vector<bool>> visited(n + 2, vector<bool>(m + 2));
    vector<vector<int>> map_step(n + 2, vector<int>(m + 2, INT_MAX));
    int step = 0;

    visited[x][y] = 1;
    map_step[x][y] = 0;
    q.push({x, y, 1});
    bool met_b = false;

    while (!q.empty() && !met_b) {
        x = get<0>(q.front());
        y = get<1>(q.front());
        step = get<2>(q.front());
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + DIR[i].f;
            int ny = y + DIR[i].s;
            if (map[nx][ny] == '#') continue;
            if (visited[nx][ny]) continue;
            visited[nx][ny] = 1;
            map_step[nx][ny] = step;
            if (map[nx][ny] == 'B') {
                met_b = true;
                break;
            }
            // map_step[nx][ny] = min(map_step[nx][ny], step);
            q.push({nx, ny, step + 1});
        }
    }

    if (!met_b) return "";

    // print_2dvec(map_step);
    auto [ex, ey] = end(n, m, map);  // end_x, end_y
    return path(map_step, ex, ey);
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

    auto [sx, sy] = start(n, m, map);  // start_x, start_y

    string ans = bfs(n, m, sx, sy, map);

    if (ans.size() != 0) {
        cout << "YES\n";
        cout << ans.size() << '\n';
        cout << ans << '\n';
    } else {
        cout << "NO\n";
    }
}
