// https://cses.fi/problemset/task/1069

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
    string in;
    cin >> in;
    int n = in.size();

    int ans = 1;
    char last = in[0];
    int tmp = 1;
    for (int i = 1; i < n; i++) {
        if (in[i] == last) {
            tmp++;
        } else {
            last = in[i];
            ans = max(ans, tmp);
            tmp = 1;
        }
    }

    ans = max(ans, tmp);

    cout << ans << '\n';
}
