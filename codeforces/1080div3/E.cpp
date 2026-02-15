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

struct node {
    int p;
    int l;
    int r;
};

int calculate_time_to_p(int i, const vec<node>& nodes, vi& time_to_p, vb& visited) {
    if (visited[i]) return time_to_p[i];

    if (nodes[i].l == 0) {
        visited[i] = true;
        time_to_p[i] = 1;
        time_to_p[i] %= (int)1e9 + 7;
        return time_to_p[i];
    }

    visited[i] = true;
    time_to_p[i] = (1 + calculate_time_to_p(nodes[i].l, nodes, time_to_p, visited)) +
                   (1 + calculate_time_to_p(nodes[i].r, nodes, time_to_p, visited)) + 1;
    time_to_p[i] %= (int)1e9 + 7;
    return time_to_p[i];
}

void solve() {
    int n;
    cin >> n;
    vec<node> nodes(n + 1);
    for (int i = 0; i < n; i++) {
        int l, r;
        cin >> l >> r;
        nodes[i + 1].l = l;
        nodes[i + 1].r = r;
        nodes[l].p = i;
        nodes[r].p = i;
    }

    vi time_to_p(n + 1);
    vb visited(n + 1);
    for (int i = 1; i <= n; i++) {
        calculate_time_to_p(i, nodes, time_to_p, visited);
    }

    // for (auto& i : time_to_p) {
    //     cout << i << ' ';
    // }
    // cout << '\n';

    vi time_to_0(n + 1);
    time_to_0[1] = time_to_p[1];
    queue<int> q;
    q.push(1);
    while (!q.empty()) {
        int top = q.front();
        q.pop();
        int l = nodes[top].l, r = nodes[top].r;
        if (l == 0) continue;
        time_to_0[l] = time_to_0[top] + time_to_p[l];
        time_to_0[l] %= (int)1e9 + 7;
        time_to_0[r] = time_to_0[top] + time_to_p[r];
        time_to_0[r] %= (int)1e9 + 7;
        q.push(l);
        q.push(r);
    }

    for (int i = 1; i <= n; i++) {
        cout << time_to_0[i] << ' ';
    }
    cout << '\n';
}

int main() {
    fio;
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
}
