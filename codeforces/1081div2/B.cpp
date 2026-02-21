#include <bits/stdc++.h>

using namespace std;
#define all(a) a.begin(), a.end()
#define fio                  \
    ios::sync_with_stdio(0); \
    cin.tie(NULL)
template <typename T>
using vec = vector<T>;
typedef long long ll;
typedef vec<int> vi;
typedef vec<vec<int>> vvi;
typedef vec<ll> vll;
typedef vec<vec<ll>> vvll;
typedef vec<bool> vb;
typedef vec<vec<bool>> vvb;
typedef vec<string> vs;
typedef vec<vec<string>> vvs;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    int cnt1 = 0;
    int cnt0 = 0;

    for (char c : s) {
        if (c == '1') cnt1++;
        else cnt0++;
    }

    if (cnt1 % 2 == 0) {
        cout << cnt1 << "\n";
        if (cnt1 == 0) return;
        for (int i = 0; i < n; i++) {
            if (s[i] == '1') {
                cout << i + 1 << " ";
            }
        }
        cout << "\n";
    } else if (cnt0 % 2 == 1) {
        cout << cnt0 << "\n";
        for (int i = 0; i < n; i++) {
            if (s[i] == '0') {
                cout << i + 1 << " ";
            }
        }
        cout << "\n";
    } else {
        cout << -1 << "\n";
    }
}

int main() {
    fio;
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
}
