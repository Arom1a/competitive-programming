#include <bits/stdc++.h>

using namespace std;
#define all(a) a.begin(), a.end()
#define fio                  \
    ios::sync_with_stdio(0); \
    cin.tie(NULL)
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vll;

bool test(ll D, vector<array<ll, 2>>& abs, int N) {
    int cnt = 0;
    ll cow = -D;  // cow_idx at least
    for (auto& i : abs) {
        while (max(cow + D, i[0]) <= i[1]) {
            cow = max(cow + D, i[0]);
            cnt++;
        }
    }
    return cnt >= N;
}

void solve() {
    int N, M;
    cin >> N >> M;

    vector<array<ll, 2>> ABs(M);
    for (int i = 0; i < M; i++) {
        ll a, b;
        cin >> a >> b;
        ABs[i] = {a, b};
    }
    sort(all(ABs));

    ll ok, ng, m;
    ok = 1;
    ng = ABs.back()[1] + 1;
    while (abs(ok - ng) > 1) {
        m = (ok + ng) / 2;
        if (test(m, ABs, N)) ok = m;
        else ng = m;
    }

    cout << ok << '\n';
}

int main() {
    freopen("socdist.in", "r", stdin);
    freopen("socdist.out", "w", stdout);
    // fio;
    int T = 1;
    while (T--) {
        solve();
    }
}
