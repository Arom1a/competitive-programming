// should use brute force instead

#include "bits/stdc++.h"

typedef long long ll;
using namespace std;

template <typename T>
void print_vector(const vector<T> &my_vec) {
    for (const T &i : my_vec)
        cout << i << ' ';
    cout << endl;
}

vector<ll> amount;
vector<vector<ll>> recipe;
vector<ll> calculated_num;

ll calculate_num(ll metal) {
    if (!calculated_num[metal]) {
        ll min_craft = INT_MAX;
        if (recipe[metal].size()) {
            for (ll recipe_metal : recipe[metal])
                min_craft = min(min_craft, calculate_num(recipe_metal));
        } else
            min_craft = 0;
        calculated_num[metal] = amount[metal] + min_craft;
    }
    return calculated_num[metal];
}

int main() {
    // input
    ll N;
    cin >> N;
    amount.resize(N + 1);
    for (ll i = 1; i <= N; i++) {
        cin >> amount[i];
    }
    ll K;
    cin >> K;
    recipe.resize(N + 1);
    for (ll i = 0; i < K; i++) {
        ll L, M;
        cin >> L >> M;
        for (ll j = 0; j < M; j++) {
            ll tmp;
            cin >> tmp;
            recipe[L].push_back(tmp);
        }
    }

    calculated_num.resize(N + 1);

    ll ans = calculate_num(N);

    cout << ans << '\n';
}
