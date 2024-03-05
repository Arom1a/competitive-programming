// https://cses.fi/problemset/task/1652

// TODO: You can still make the algorithm better!!!!!!
// TODO: You can still make the algorithm better!!!!!!
// TODO: You can still make the algorithm better!!!!!!

#include "bits/stdc++.h"

typedef long long ll;
using namespace std;

template <typename T>
void print_vector(const vector<T>& my_vec) {
    for (const T& i : my_vec)
        cout << i << ' ';
    cout << endl;
}

int main() {
    // input
    int n, q;
    cin >> n >> q;
    vector<string> grid(n);
    for (int i = 0; i < n; i++)
        cin >> grid[i];

    vector<vector<int>> num_grid(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == '.')
                num_grid[i][j] = 0;
            else
                num_grid[i][j] = 1;
        }
    }

    vector<vector<int>> sum_grid(n, vector<int>(n + 1));
    for (int i = 0; i < n; i++)
        partial_sum(num_grid[i].rbegin(), num_grid[i].rend(), sum_grid[i].rbegin() + 1);

    // for (int i = 0; i < n; i++) // debug
    // {
    //     print_vector(num_grid[i]); // debug
    //     print_vector(sum_grid[i]); // debug
    // }

    // test
    // vector<int> c{};
    // int q = 1, N = c.size();
    // expected:

    // answer below
    while (q--) {
        int x1, y1, x2, y2;
        cin >> y1 >> x1 >> y2 >> x2;
        x1--;
        x2--;
        y1--;
        y2--;
        vector<int> c(n);
        for (int i = 0; i < n; i++) {}

        int ans = 0;

        for (int y = y1; y <= y2; y++)
            ans += sum_grid[y][x1] - sum_grid[y][x2 + 1];

        cout << ans << '\n';
    }
}
