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

class DSU {
    int size;
    int num_of_componenets;
    vi parent;

    void init(int n) {
        size = n;
        num_of_componenets = n;
        parent = vi(n);
        for (int i = 0; i < n; i++)
            parent[i] = i;
    }

    int get(int x) { return parent[x]; }

    bool is_same_set(int a, int b) { return get(a) == get(b); }

    bool unite(int a, int b) {
        int pa = get(a), pb = get(b);
        if (pa == pb) return false;

        return false;
    }
};

// struct DSU {
//     vi e;
//     int num;
//
//     void init(int N) {
//         e = vi(N, -1);
//         num = N;
//     }
//
//     int get(int x) { return e[x] < 0 ? x : e[x] = get(e[x]); }
//
//     bool sameSet(int a, int b) { return get(a) == get(b); }
//
//     int size(int x) { return -e[get(x)]; }
//
//     bool unite(int x, int y) {  // union by size
//         x = get(x), y = get(y);
//         if (x == y) return 0;
//         if (e[x] > e[y]) swap(x, y);
//         e[x] += e[y];
//         num -= 1;
//         e[y] = x;
//         return 1;
//     }
// };
