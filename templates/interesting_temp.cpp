// BEGIN: main.cpp
#line 1 "main.cpp"
#include <bits/stdc++.h>
using namespace std;

#define all(a) a.begin(), a.end()
#define pb push_back
#define sz(a) ((int)a.size())

using ll = long long;
using u32 = unsigned int;
using u64 = unsigned long long;
using i128 = __int128;
using u128 = unsigned __int128;
using f128 = __float128;

using pii = pair<int, int>;
using pll = pair<ll, ll>;

template <typename T>
using vc = vector<T>;
template <typename T>
using vvc = vc<vc<T>>;
template <typename T>
using vvvc = vc<vvc<T>>;

using vi = vc<int>;
using vll = vc<ll>;
using vvi = vc<vi>;
using vvll = vc<vll>;

#define vv(type, name, n, ...) vector<vector<type>> name(n, vector<type>(__VA_ARGS__))
#define vvv(type, name, n, m, ...) \
    vector<vector<vector<type>>> name(n, vector<vector<type>>(m, vector<type>(__VA_ARGS__)))

template <typename T>
using min_heap = priority_queue<T, vector<T>, greater<T>>;
template <typename T>
using max_heap = priority_queue<T>;

// https://trap.jp/post/1224/
#define rep1(n) for (ll i = 0; i < (ll)(n); ++i)
#define rep2(i, n) for (ll i = 0; i < (ll)(n); ++i)
#define rep3(i, a, b) for (ll i = (ll)(a); i < (ll)(b); ++i)
#define rep4(i, a, b, c) for (ll i = (ll)(a); i < (ll)(b); i += (c))
#define cut4(a, b, c, d, e, ...) e
#define rep(...) cut4(__VA_ARGS__, rep4, rep3, rep2, rep1)(__VA_ARGS__)
#define per1(n) for (ll i = ((ll)n) - 1; i >= 0; --i)
#define per2(i, n) for (ll i = ((ll)n) - 1; i >= 0; --i)
#define per3(i, a, b) for (ll i = ((ll)a) - 1; i >= (ll)(b); --i)
#define per4(i, a, b, c) for (ll i = ((ll)a) - 1; i >= (ll)(b); i -= (c))
#define per(...) cut4(__VA_ARGS__, per4, per3, per2, per1)(__VA_ARGS__)
#define rep_subset(i, s) for (ll i = (s); i >= 0; i = (i == 0 ? -1 : (i - 1) & (s)))

template <typename T, typename S>
constexpr T ifloor(const T a, const S b) {
    return a / b - (a % b && (a ^ b) < 0);
}

template <typename T, typename S>
constexpr T iceil(const T a, const S b) {
    return ifloor(a + b - 1, b);
}

template <typename T>
void sort_unique(vector<T>& vec) {
    sort(vec.begin(), vec.end());
    vec.resize(unique(vec.begin(), vec.end()) - vec.begin());
}

template <typename T, typename S>
constexpr bool chmin(T& a, const S b) {
    if (a > b) return a = b, true;
    return false;
}

template <typename T, typename S>
constexpr bool chmax(T& a, const S b) {
    if (a < b) return a = b, true;
    return false;
}

template <typename T, typename S>
istream& operator>>(istream& i, pair<T, S>& p) {
    return i >> p.first >> p.second;
}

template <typename T, typename S>
ostream& operator<<(ostream& o, const pair<T, S>& p) {
    return o << p.first << ' ' << p.second;
}

#ifdef i_am_noob
#define bug(...) cerr << "#" << __LINE__ << ' ' << #__VA_ARGS__ << "- ", _do(__VA_ARGS__)

template <typename T>
void _do(vector<T> x) {
    for (auto i : x)
        cerr << i << ' ';
    cerr << "\n";
}

template <typename T>
void _do(set<T> x) {
    for (auto i : x)
        cerr << i << ' ';
    cerr << "\n";
}

template <typename T>
void _do(unordered_set<T> x) {
    for (auto i : x)
        cerr << i << ' ';
    cerr << "\n";
}

template <typename T>
void _do(T&& x) {
    cerr << x << endl;
}

template <typename T, typename... S>
void _do(T&& x, S&&... y) {
    cerr << x << ", ";
    _do(y...);
}
#else
#define bug(...) 777771449
#endif

template <typename T>
void print(vector<T> x) {
    for (auto i : x)
        cout << i << ' ';
    cout << "\n";
}

template <typename T>
void print(set<T> x) {
    for (auto i : x)
        cout << i << ' ';
    cout << "\n";
}

template <typename T>
void print(unordered_set<T> x) {
    for (auto i : x)
        cout << i << ' ';
    cout << "\n";
}

template <typename T>
void print(T&& x) {
    cout << x << "\n";
}

template <typename T, typename... S>
void print(T&& x, S&&... y) {
    cout << x << ' ';
    print(y...);
}

template <typename T>
istream& operator>>(istream& i, vector<T>& vec) {
    for (auto& x : vec)
        i >> x;
    return i;
}

vvi read_graph(int n, int m, int base = 1) {
    vvi adj(n);
    for (int i = 0, u, v; i < m; ++i) {
        cin >> u >> v, u -= base, v -= base;
        adj[u].pb(v), adj[v].pb(u);
    }
    return adj;
}

vvi read_tree(int n, int base = 1) {
    return read_graph(n, n - 1, base);
}

template <typename T, typename S>
pair<T, S> operator+(const pair<T, S>& a, const pair<T, S>& b) {
    return {a.first + b.first, a.second + b.second};
}

template <typename T>
constexpr T inf = 0;
template <>
constexpr int inf<int> = 0x3f3f3f3f;
template <>
constexpr ll inf<ll> = 0x3f3f3f3f3f3f3f3f;

template <typename T>
vector<T> operator+=(vector<T>& a, int val) {
    for (auto& i : a)
        i += val;
    return a;
}

template <typename T>
T isqrt(const T& x) {
    T y = sqrt(x + 2);
    while (y * y > x)
        y--;
    return y;
}

#define ykh mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())

//#include "library/mod/modint.hpp"
//using mint=modint<998244353>;
//using mint=modint<1000000007>;

// BEGIN: library/misc/fast_io.hpp
#line 1 "library/misc/fast_io.hpp"

struct fast_io {
    static const int M = 1 << 15;
    char buf[M], *p = buf, *q = buf;

    inline char readchar() {
        if (p == q && (q = (p = buf) + fread(buf, 1, M, stdin)) == buf) return EOF;
        else return *p++;
    }

    bool readint(int& x) {
        int c = readchar(), neg = 0;
        x = 0;
        while ((c < '0' || c > '9') && c != '-' && c != EOF)
            c = readchar();
        if (c == EOF) return false;
        if (c == '-') neg = 1, c = readchar();
        while (c >= '0' && c <= '9')
            x = (x << 3) + (x << 1) + (c ^ '0'), c = readchar();
        if (neg) x = -x;
        return true;
    }

    bool readll(ll& x) {
        int c = readchar(), neg = 0;
        x = 0;
        while ((c < '0' || c > '9') && c != '-' && c != EOF)
            c = readchar();
        if (c == EOF) return false;
        if (c == '-') neg = 1, c = readchar();
        while (c >= '0' && c <= '9')
            x = (x << 3) + (x << 1) + (c ^ '0'), c = readchar();
        if (neg) x = -x;
        return true;
    }

    bool readstr(string& a) {
        a.clear();
        int c = readchar();
        while (c == ' ' || c == '\n')
            c = readchar();
        if (c == EOF) return false;
        while (c != ' ' && c != '\n' && c != EOF)
            a += c, c = readchar();
        return true;
    }

    char buf2[M], *r = buf2;

    void writechar(char c) {
        (*r++) = c;
        if (r == buf2 + M) r = buf2, fwrite(buf2, 1, M, stdout);
    }

    void writestr(string a, char end = '\n') {
        for (char c : a)
            writechar(c);
        if (end) writechar(end);
    }

    void writeint(int x, char end = '\n') {
        if (x < 0) writechar('-'), x *= -1;
        if (x == 0) {
            writechar('0');
            if (end) writechar(end);
            return;
        }
        char tmp[14], *ptr = tmp;
        while (x) {
            (*ptr++) = '0' + (x % 10);
            x /= 10;
        }
        while (ptr != tmp)
            writechar(*--ptr);
        if (end) writechar(end);
    }

    void writell(ll x, char end = '\n') {
        if (x < 0) writechar('-'), x *= -1;
        if (x == 0) {
            writechar('0');
            if (end) writechar(end);
            return;
        }
        char tmp[25], *ptr = tmp;
        while (x) {
            (*ptr++) = '0' + (x % 10);
            x /= 10;
        }
        while (ptr != tmp)
            writechar(*--ptr);
        if (end) writechar(end);
    }

    void endl() { writechar('\n'); }

    void end() { fwrite(buf2, 1, r - buf2, stdout); }
} io;  // END: library/misc/fast_io.hpp

#line 111 "main.cpp"
// BEGIN: library/ds/dsu/dsu.hpp
#line 1 "library/ds/dsu/dsu.hpp"

struct dsu {
    int n;
    vector<int> par, siz;

    void build(int _n) {
        n = _n;
        par.resize(n);
        siz.resize(n);
        for (int i = 0; i < n; ++i) {
            par[i] = i;
            siz[i] = 1;
        }
    }

    dsu() {}

    dsu(int _n) { build(_n); }

    int find(int x) {
        if (par[x] == x) return x;
        return par[x] = find(par[x]);
    }

    int size(int x) { return siz[find(x)]; }

    bool merge(int x, int y) {
        x = find(x), y = find(y);
        if (x == y) return false;
        if (siz[x] < siz[y]) swap(x, y);
        siz[x] += siz[y];
        par[y] = x;
        return true;
    }
};  // END: library/ds/dsu/dsu.hpp

#line 112 "main.cpp"

void mango() {
    int n;
    io.readint(n);
    vc<string> a(n), b;
    rep(n) io.readstr(a[i]);
    rep(n) if (a[i][i] == '0') {
        print("No");
        return;
    }
    b = a;
    vi out(n);
    rep(n) rep(j, n) {
        out[i] += a[i][j] == '1';
    }
    vi ord(n), vis(n);
    auto counting_sort = [&]() {
        vi cnt(n + 2);
        rep(n) ord[i] = -1;
        rep(n) if (!vis[i]) {
            cnt[out[i] + 1]++;
        }
        rep(i, 1, n + 2) cnt[i] += cnt[i - 1];
        rep(n) if (!vis[i]) {
            ord[cnt[out[i]]++] = i;
        }
    };
    vc<pii> res;
    vi ord2;
    rep(_, n) {
        counting_sort();
        if (_ == 0) {
            ord2 = ord;
        }
        int u = ord[0];
        vi round;
        rep(i, 1, n) {
            if (ord[i] == -1) break;
            int v = ord[i];
            if (a[v][u] == '1') {
                bool good = 1;
                for (auto v2 : round)
                    if (a[v][v2] == '1') {
                        good = 0;
                        break;
                    }
                if (good) {
                    round.pb(v);
                }
            }
        }
        vis[u] = 1, out[u] = 0;
        rep(n) if (!vis[i]) {
            if (a[i][u] == '1') {
                a[i][u] = '0';
                out[i]--;
            }
        }
        for (auto v : round) {
            res.pb({v, u});
        }
        if (sz(res) > n - 1) {
            print("No");
            return;
        }
    }
    if (sz(res) != n - 1) {
        print("No");
        return;
    }
    vvi adj(n);
    dsu d(n);
    for (auto [u, v] : res) {
        adj[u].pb(v);
        d.merge(u, v);
    }
    if (d.size(0) != n) {
        print("No");
        return;
    }
    for (auto u : ord2) {
        string tmp;
        rep(n) tmp += '0';
        tmp[u] = '1';
        for (auto v : adj[u]) {
            rep(n) {
                if (b[v][i] == '1') {
                    tmp[i] = '1';
                }
            }
        }
        if (tmp != b[u]) {
            print("No");
            return;
        }
    }
    print("Yes");
    for (auto [x, y] : res)
        print(x + 1, y + 1);
}

signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    cout << fixed << setprecision(20);
    int t = 1;
    //cin >> t;
    io.readint(t);
    while (t--)
        mango();
}

// END: main.cpp
