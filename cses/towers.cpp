#include "bits/stdc++.h"

typedef long long ll;
using namespace std;

template <typename T>
void print_vector(const vector<T> &my_vec) {
    for (const T &i : my_vec)
        cout << i << ' ';
    cout << endl;
}

int main() {
    // input
    int n;
    cin >> n;
    vector<ll> blocks(n);
    for (ll &i : blocks) {
        cin >> i;
    }

    // test
    // int n = ;
    // vector<int> c{};
    // expected:

    // answer below
    vector<stack<ll>> towers;
    stack<ll> first_block;
    first_block.push(blocks[0]);
    towers.push_back(first_block);
    blocks.erase(blocks.begin());
    // print_vector(blocks);

    for (ll &b : blocks) {
        pair<ll, ll> min_diff_p = make_pair(-1, INT_MAX);  // position, diff
        for (ll i = 0; i < towers.size(); i++) {
            ll top = towers[i].top(), diff = top - b;
            // cout << "wtf" << '\n';  // debug
            // cout << b << '\n';  // debug
            if (0 < diff && diff < min_diff_p.second) {
                min_diff_p = make_pair(i, diff);
            }
        }
        if (min_diff_p.first == -1) {
            stack<ll> tmp_stack;
            tmp_stack.push(b);
            towers.push_back(tmp_stack);
        } else {
            towers[min_diff_p.first].push(b);
        }
    }

    int ans = towers.size();
    cout << ans << '\n';
}
