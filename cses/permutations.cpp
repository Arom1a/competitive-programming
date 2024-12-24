// https://cses.fi/problemset/task/1070

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
    int n;
    cin >> n;

    if (n == 2 || n == 3)
        cout << "NO SOLUTION" << endl;
    else {
        for (int i = 2; i <= n; i += 2) cout << i << ' ';
        for (int i = 1; i <= n; i += 2) cout << i << ' ';
        cout << endl;
    }
}
