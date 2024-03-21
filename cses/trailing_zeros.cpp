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
    ll n;
    cin >> n;
    int exp = 1;
    while (pow(5, exp + 1) < n) exp++;
    int ans = 0;
    for (int i = 1; i <= exp; i++) ans += n / pow(5, i);

    cout << ans << '\n';
}
