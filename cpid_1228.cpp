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
    int N;
    cin >> N;
    vector<pair<ll, char>> c(N);
    int G_count = 0, L_count = 0;
    for (auto &[location, direction] : c) {
        cin >> direction >> location;
        if (direction == 'G')
            G_count++;
        if (direction == 'L')
            L_count++;
    }

    sort(c.begin(), c.end());

    int ans = INT_MAX;
    int count = G_count;
    for (int i = 0; i < N; i++) {
        if (c[i].second == 'G')
            count--;
        if (c[i].second == 'L')
            count++;
        ans = min(ans, count);
    }

    cout << ans << '\n';
}
