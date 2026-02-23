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

struct card {
    ll cost;
    int id;
};

struct card_cmp {
    bool operator()(const card& a, const card& b) { return a.cost > b.cost; }
};

int main() {
    fio;
    int N, H;
    cin >> N >> H;
    vll as(N);
    for (int i = 0; i < N; i++) {
        cin >> as[i];
    }
    int k;
    cin >> k;
    vb is_win(N, 0);
    for (int i = 0; i < k; i++) {
        int in;
        cin >> in;
        is_win[in - 1] = 1;
    }

    priority_queue<card, vec<card>, card_cmp> w, nw;
    queue<card> q;
    for (int i = 0; i < H; i++) {
        if (is_win[i]) w.push({as[i], i});
        else nw.push({as[i], i});
    }
    for (int i = H; i < N; i++) {
        q.push({as[i], i});
    }

    int trans_len = N - H;
    vll init_cost(trans_len);
    vll init_wins(trans_len);
    ll cost = 0;
    ll wins = 0;

    for (int i = 0; i < trans_len; i++) {
        card top;
        if (!w.empty()) {
            top = w.top();
            w.pop();
        } else {
            top = nw.top();
            nw.pop();
        }

        cost += top.cost;
        wins += is_win[top.id];
        init_cost[i] = cost;
        init_wins[i] = wins;

        q.push(top);
        card drawn = q.front();
        q.pop();

        if (is_win[drawn.id]) w.push(drawn);
        else nw.push(drawn);
    }

    int per_len = N - H + 1;
    vll cycle_cost(per_len);
    vll cycle_wins(per_len);
    ll p_cost = 0;
    ll p_wins = 0;

    for (int i = 0; i < per_len; i++) {
        card top;
        if (!w.empty()) {
            top = w.top();
            w.pop();
        } else {
            top = nw.top();
            nw.pop();
        }

        p_cost += top.cost;
        p_wins += is_win[top.id];
        cycle_cost[i] = p_cost;
        cycle_wins[i] = p_wins;

        q.push(top);
        card drawn = q.front();
        q.pop();

        if (is_win[drawn.id]) w.push(drawn);
        else nw.push(drawn);
    }

    int Q;
    cin >> Q;
    while (Q--) {
        ll t;
        cin >> t;
        ll ans = 0;

        auto it = upper_bound(all(init_cost), t);

        if (it == init_cost.begin()) {
            cout << 0 << "\n";
            continue;
        }

        int idx = (int)distance(init_cost.begin(), it) - 1;
        ans += init_wins[idx];

        if (idx == trans_len - 1) {
            ll rem_t = t - init_cost.back();
            ll full_cycles = rem_t / cycle_cost.back();
            ans += full_cycles * cycle_wins.back();
            ll rem_frac = rem_t % cycle_cost.back();
            auto p_it = upper_bound(all(cycle_cost), rem_frac);

            if (p_it != cycle_cost.begin()) {
                int p_idx = (int)distance(cycle_cost.begin(), p_it) - 1;
                ans += cycle_wins[p_idx];
            }
        }

        cout << ans << "\n";
    }
}
