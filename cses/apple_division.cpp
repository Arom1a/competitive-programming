// https://cses.fi/problemset/task/1623

#include "bits/stdc++.h"

typedef long long ll;
using namespace std;

// Method 1 (my ugly one):
// string bin(int n) {
//     if (n / 2 == 0) return "1";
//     return bin(n / 2) + to_string(n % 2);
// }

// ll dot_product_diff(int n, vector<int> p) {
//     string str = bin(n);
//     while (str.size() < p.size())
//         str = "0" + str;
//     ll podt1 = 0, podt2 = 0;
//     for (int i = 0; i < p.size(); i++) {
//         podt1 += (str[i] - '0') * p[i];
//     }
//     for (char &i : str)
//         i = (i == '0') ? '1' : '0';
//     for (int i = 0; i < p.size(); i++) {
//         podt2 += (str[i] - '0') * p[i];
//     }

//     return abs(podt1 - podt2);
// }

// int main() {
//     int n;
//     cin >> n;
//     vector<int> p(n);
//     for (int &i : p)
//         cin >> i;

//     ll ans = LLONG_MAX;

//     for (int i = 0; i < (ll)pow(2, n); i++)
//         ans = min(ans, dot_product_diff(i, p));
//     cout << ans << endl;
// }

// -------------------------------------------------------------------------------------------------
// Method 2:
ll tree(int depth, ll sum1, ll sum2, const vector<int> &p, const int &n) {
    if (depth == n) return abs(sum1 - sum2);
    return min(tree(depth + 1, sum1 + p[depth], sum2, p, n),
               tree(depth + 1, sum1, sum2 + p[depth], p, n));
}

int main() {
    int n;
    cin >> n;
    vector<int> p(n);
    for (int &i : p)
        cin >> i;

    ll ans = tree(0, 0, 0, p, n);
    cout << ans << '\n';
}
