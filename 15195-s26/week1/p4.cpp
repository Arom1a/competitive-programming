#include <bits/stdc++.h>

using namespace std;
#define all(a) a.begin(), a.end()
#define fio                  \
    ios::sync_with_stdio(0); \
    cin.tie(NULL)
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vll;

// 0 = up, 1 = right, 2 = down, 3 = left
array<int, 4> rotated(const array<int, 4>& base, int k) {
    array<int, 4> rtn;
    for (int t = 0; t < 4; t++)
        rtn[t] = base[(t - k + 4) % 4];
    return rtn;
}

void solve() {
    int N, M;
    cin >> N >> M;
    vector<string> G(N);
    for (int i = 0; i < N; i++)
        cin >> G[i];

    unordered_map<char, array<int, 4>> base;
    // top, right, bottom, left
    base['A'] = {0, 0, 0, 0};
    base['B'] = {1, 0, 1, 0};
    base['C'] = {1, 1, 0, 0};
    base['D'] = {1, 1, 1, 1};

    vector<int> t(M, 0);

    for (int i = 0; i < N; i++) {
        int l = 0;  // left
        for (int j = 0; j < M; j++) {
            int t_in = t[j];
            int l_in = l;
            char c = G[i][j];
            bool found = false;
            int r_out = 0, b_out = 0;

            for (int k = 0; k < 4 && !found; k++) {
                array<int, 4> conn = rotated(base[c], k);
                if (conn[3] == l_in && conn[0] == t_in) {
                    r_out = conn[1];
                    b_out = conn[2];
                    found = true;
                }
            }

            if (!found) {
                cout << "Impossible\n";
                return;
            }

            l = r_out;
            t[j] = b_out;
        }

        if (l != 0) {
            cout << "Impossible\n";
            return;
        }
    }

    for (int j = 0; j < M; j++) {
        if (t[j] != 0) {
            cout << "Impossible\n";
            return;
        }
    }

    cout << "Possible\n";
}

int main() {
    fio;

    int T = 1;
    while (T--) {
        solve();
    }
}
