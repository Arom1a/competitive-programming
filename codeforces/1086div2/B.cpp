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

struct Card {
    int idx;
    int cost;
};

void solve() {
    int n, k, p, m;
    cin >> n >> k >> p >> m;
    p--;
    vec<Card> cards;
    Card win_card;
    cards.reserve(n);
    for (int i = 0; i < n; i++) {
        int cost;
        cin >> cost;
        if (i != p) {
            cards.push_back({i, cost});
        } else {
            win_card = {i, cost};
        }
    }
    sort(all(cards), [](Card& a, Card& b) {
        if (a.cost == b.cost) return a.idx > b.idx;
        else return a.cost < b.cost;
    });
    for (int i = 1; i < k; i++) {
        cards.pop_back();
    }
    cards.push_back(win_card);
    sort(all(cards), [](Card& a, Card& b) { return a.idx < b.idx; });

    int init_i = 0;
    int init_cost = 0;
    while (cards[init_i].idx < p) {
        init_cost += cards[init_i].cost;
        init_i++;
    }

    m -= init_cost;

    if (m <= 0) {
        cout << "0\n";
        return;
    }
    m -= win_card.cost;
    if (m < 0) {
        cout << "0\n";
        return;
    }
    int ans = 1;

    int cycle_cost = 0;
    for (int i = 0; i < (int)cards.size(); i++) {
        cycle_cost += cards[i].cost;
    }
    ans += m / cycle_cost;
    cout << ans << '\n';
}

int main() {
    fio;
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
}
