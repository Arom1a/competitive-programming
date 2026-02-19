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
    int num;

    void init(int N) {
        e = vi(N, -1);
        num = N;
    }

    int get(int x) { return e[x] < 0 ? x : e[x] = get(e[x]); }

    bool sameSet(int a, int b) { return get(a) == get(b); }

    int size(int x) { return -e[get(x)]; }

    bool unite(int x, int y) {  // union by size
        x = get(x), y = get(y);
        if (x == y) return 0;
        if (e[x] > e[y]) swap(x, y);
        e[x] += e[y];
        num -= 1;
        e[y] = x;
        return 1;
    }
};

void solve() {
    int N, M;
    cin >> N >> M;
    vvi threads(M);
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        threads[i] = {a - 1, b - 1};
    }
    int Q;
    cin >> Q;
    vi qs(Q);
    for (int i = 0; i < Q; i++) {
        cin >> qs[i];
    }

    unordered_set<int> thread_nums;
    for (int i = 0; i < M; i++) {
        thread_nums.insert(i);
    }
    for (int& i : qs) {
        thread_nums.erase(i - 1);
    }

    DSU dsu;
    dsu.init(N);
    for (const int& i : thread_nums) {
        dsu.unite(threads[i][0], threads[i][1]);
    }

    vi ans;
    for (int i = Q - 1; i >= 0; i--) {
        ans.push_back(dsu.num);
        dsu.unite(threads[qs[i] - 1][0], threads[qs[i] - 1][1]);
    }
    for (int i = Q - 1; i >= 0; i--) {
        cout << ans[i] << ' ';
    }
    cout << '\n';
}

int main() {
    fio;
    int T = 1;
    while (T--) {
        solve();
    }
}
