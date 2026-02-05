#include <bits/stdc++.h>

using namespace std;
#define all(a) a.begin(), a.end()
#define fio                  \
    ios::sync_with_stdio(0); \
    cin.tie(NULL)
template <typename T>
using vec = vector<T>;
typedef long long ll;
typedef vec<int> vi;
typedef vec<vec<int>> vvi;
typedef vec<ll> vll;
typedef vec<vec<ll>> vvll;
typedef vec<bool> vb;
typedef vec<vec<bool>> vvb;
typedef vec<string> vs;
typedef vec<vec<string>> vvs;

struct DSU {
    vi e;

    void init(int N) { e = vi(N, -1); }

    int get(int x) { return e[x] < 0 ? x : e[x] = get(e[x]); }

    bool sameSet(int a, int b) { return get(a) == get(b); }

    int size(int x) { return -e[get(x)]; }

    bool unite(int x, int y) {  // union by size
        x = get(x), y = get(y);
        if (x == y) return 0;
        if (e[x] > e[y]) swap(x, y);
        e[x] += e[y];
        e[y] = x;
        return 1;
    }
};

bool comparator(vector<int>& a, vector<int>& b) {
    return a[2] < b[2];
}

void solve() {
    int n, k;
    cin >> n >> k;
    DSU dsu;
    dsu.init(n);
    {
        int tmp, tmp2;
        cin >> tmp;
        for (int i = 0; i < k - 1; i++) {
            cin >> tmp2;
            tmp--;
            tmp2--;
            dsu.unite(tmp, tmp2);
        }
    }

    vvi edges;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int w;
            cin >> w;
            if (j > i) {
                edges.push_back({w, i, j});
            }
        }
    }
    sort(all(edges));

    int cost = 0;
    for (auto& e : edges) {
        int w = e[0], x = e[1], y = e[2];

        if (dsu.get(x) != dsu.get(y)) {
            dsu.unite(x, y);
            cost += w;
            if (dsu.size(0) == n) break;
        }
    }

    cout << cost << '\n';
}

int main() {
    fio;
    int T = 1;
    while (T--) {
        solve();
    }
}
