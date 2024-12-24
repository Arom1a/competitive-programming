// https://cses.fi/problemset/task/1624

#include "bits/stdc++.h"
#define all(a) a.begin(), a.end()

typedef long long ll;
using namespace std;

template <typename T>
void print_vector(const vector<T> &my_vec) {
    for (const T &i : my_vec)
        cout << i << ' ';
    cout << endl;
}

bool check_reserved_okay(const vector<int> &t, const vector<vector<int>> &b) {
    for (int i = 0; i < 8; i++) {
        for (auto j : b[i])
            if (t[i] == j) return false;
    }

    return true;
}

bool check_surround_okay(const vector<int> &t) {
    int p[] = {-1, 1};
    for (int j : p) {
        if (t[0 + 1] == (t[0] + j)) return false;
    }

    for (int i = 1; i < 7; i++) {
        for (int j : p) {
            for (int k : p)
                if (t[i + j] == t[i] + k) return false;
        }
    }

    for (int j : p) {
        if (t[7 - 1] == (t[7] + j)) return false;
    }

    return true;
}

bool check_diagonal_okay(const vector<int> &t) {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (i == j) continue;

            if (t[j] == t[i] + (i - j)) return false;
            if (t[j] == t[i] - (i - j)) return false;
        }
    }

    return true;
}

int main() {
    vector<vector<int>> b(8, vector<int>());

    for (int i = 1; i <= 8; i++) {
        string r;
        cin >> r;
        for (int j = 0; j < 8; j++) {
            if (r[j] == '*') b[j].push_back(i);
        }
    }

    // for (int i = 1; i <= 8; i++)
    //     print_vector(b[i]);

    vector<int> t;
    t.reserve(8);
    for (int i = 1; i <= 8; i++)
        t.push_back(i);

    int ans = 0;

    while (next_permutation(t.begin(), t.end())) {
        if (!check_reserved_okay(t, b)) continue;
        if (!check_surround_okay(t)) continue;
        if (!check_diagonal_okay(t)) continue;

        ans++;
    }

    cout << ans << endl;
}
