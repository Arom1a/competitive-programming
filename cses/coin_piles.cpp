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
    int t;
    cin >> t;
    string ans = "";
    while (t--) {
        int a, b;
        cin >> a >> b;
        int diff = abs(a - b);
        a -= ((a > b) + 1) * diff;
        if (a < 0) ans += "NO\n";
        // cout << "NO" << '\n';
        else if (a % 3 == 0) ans += "YES\n";
        // cout << "YES" << '\n';
        else ans += "NO\n";
        // cout << "NO" << '\n';
    }
    cout << ans;
}
