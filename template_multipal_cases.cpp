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
    int T;
    cin >> T;

    // test
    // vector<int> c{};
    // int T = 1, N = c.size();
    // expected:

    // answer below
    while (T--) {
        int N;
        cin >> N;
        vector<int> c(N);
        for (int i = 0; i < N; i++) {
            cin >> c[i];
        }

        int ans = 0;

        cout << ans << '\n';
    }
}
