// https://cses.fi/problemset/task/1625

#include "bits/stdc++.h"

using namespace std;

bool v[9][9];
int tokens[49];
int dx[] = {0, 0, -1, 1};  // UDLR
int dy[] = {-1, 1, 0, 0};  // UDLR

int dfs(int x, int y, int d) {
    if (x == 1 && y == 7) {
        if (d == 49) return 1;
        return 0;
    }
    if (d == 49) return 0;

    // ?0?
    // 1o1
    // ?0?
    if (v[x + 1][y] && v[x - 1][y] && !v[x][y + 1] && !v[x][y - 1]) return 0;
    // ?1?
    // 0o0
    // ?1?
    if (v[x][y + 1] && v[x][y - 1] && !v[x + 1][y] && !v[x - 1][y]) return 0;
    // 10?
    // 0o?
    // ???
    if (v[x - 1][y - 1] && !v[x - 1][y] && !v[x][y - 1]) return 0;
    // ?01
    // ?o0
    // ???
    if (v[x - 1][y + 1] && !v[x - 1][y] && !v[x][y + 1]) return 0;
    // ???
    // 0o?
    // 10?
    if (v[x + 1][y - 1] && !v[x + 1][y] && !v[x][y - 1]) return 0;
    // ???
    // ?o0
    // ?01
    if (v[x + 1][y + 1] && !v[x + 1][y] && !v[x][y + 1]) return 0;

    int rtn = 0;
    v[x][y] = 1;

    int c = tokens[d - 1];

    if (c >= 0) {
        x += dx[c];
        y += dy[c];
        if (!v[x][y]) rtn += dfs(x, y, d + 1);
        x -= dx[c];
        y -= dy[c];
    } else {
        for (int i = 0; i < 4; i++) {
            x += dx[i];
            y += dy[i];
            if (!v[x][y]) rtn += dfs(x, y, d + 1);
            x -= dx[i];
            y -= dy[i];
        }
    }

    v[x][y] = 0;
    return rtn;
}

int main() {
    string in;
    cin >> in;

    for (int i = 0; i < 49; i++) {
        tokens[i] = (in[i] == 'U')   ? 0
                    : (in[i] == 'D') ? 1
                    : (in[i] == 'L') ? 2
                    : (in[i] == 'R') ? 3
                                     : -1;
    }

    for (int i = 0; i < 8; i++) {
        v[0][i] = 1;
        v[8][i] = 1;
        v[i][0] = 1;
        v[i][8] = 1;
    }

    int ans = dfs(1, 1, 1);

    cout << ans << endl;
}
