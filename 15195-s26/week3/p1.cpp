#include <bits/stdc++.h>

using namespace std;
#define all(a) a.begin(), a.end()
#define fio                  \
    ios::sync_with_stdio(0); \
    cin.tie(NULL)
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<long long> vll;
typedef vector<vector<long long>> vvll;
typedef vector<bool> vb;
typedef vector<vector<bool>> vvb;
typedef vector<string> vs;
typedef vector<vector<string>> vvs;

array<int, 5> d = {0, 1, 0, -1, 0};

struct vertex {
    int x;
    int y;
};

void back_trace(vector<vector<vertex>>& pred, vertex a, vertex b) {
    int ix = b.x, iy = b.y;
    int step = 0;
    string dirs;
    while (ix != a.x || iy != a.y) {
        vertex p = pred[iy][ix];
        if (ix == p.x) dirs.push_back(iy > p.y ? 'D' : 'U');
        else dirs.push_back(ix > p.x ? 'R' : 'L');
        ix = p.x, iy = p.y;
        step += 1;
    }
    reverse(all(dirs));
    cout << step << '\n';
    cout << dirs << '\n';
}

void solve() {
    int n, m;
    cin >> n >> m;

    vs map(n);
    vvb visited(n, vb(m, 0));
    vector<vector<vertex>> pred(n, vector<vertex>(m, {-1, -1}));
    for (int i = 0; i < n; i++)
        cin >> map[i];

    int ax = -1, ay = -1;
    int bx = -1, by = -1;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (map[j][i] == 'A') {
                ax = i, ay = j;
            }
            if (map[j][i] == 'B') {
                bx = i, by = j;
            }
        }
    }

    queue<vertex> q;
    q.push({ax, ay});
    visited[ay][ax] = 1;
    while (!q.empty()) {
        vertex v = q.front();
        int ix = v.x, iy = v.y;
        q.pop();

        if (ix == bx && iy == by) {
            cout << "YES\n";
            back_trace(pred, {ax, ay}, {bx, by});
            return;
        }

        for (int di = 0; di < 4; di++) {
            int dx = d[di], dy = d[di + 1];
            int nix = ix + dx, niy = iy + dy;
            if (!(0 <= nix && nix < m && 0 <= niy && niy < n)) continue;
            if (map[niy][nix] == '#') continue;
            if (visited[niy][nix]) continue;

            visited[niy][nix] = true;
            q.push({nix, niy});
            pred[niy][nix] = v;
        }
    }

    cout << "NO\n";
}

int main() {
    fio;

    int T = 1;
    while (T--) {
        solve();
    }
}
