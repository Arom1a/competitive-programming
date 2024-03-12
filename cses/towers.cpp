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

    // test
    // int n = ;
    // vector<int> c{};
    // expected:

    // answer below
    int ans = 0;
    vector<ll> tower_tops;
    for (int i = 0; i < n; i++) {
        ll b;
        cin >> b;
        auto place = upper_bound(tower_tops.begin(), tower_tops.end(), b);
        if (place == tower_tops.end()) {
            tower_tops.push_back(b);
        } else {
            *place = b;
        }
    }
    ans = tower_tops.size();

    cout << ans << '\n';
}
