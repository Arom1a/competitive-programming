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

template <typename T>
void print_1dvec(const vector<T>& vec) {
    for (const T& i : vec)
        cout << i << ' ';
    cout << '\n';
}

void solve() {
    int n;
    string in;
    cin >> n >> in;
    vb s;
    s.reserve(n);
    for (char& c : in) {
        if (c == '0') s.push_back(0);
        else s.push_back(1);
    }
    vb not_available(n);
    for (int i = 0; i < n; i++) {
        if (s[i]) {
            not_available[i] = 1;
            if (0 <= i - 1 && i - 1 < n) not_available[i - 1] = 1;
            if (0 <= i + 1 && i + 1 < n) not_available[i + 1] = 1;
        }
    }
    // calc_empty_seats();
    int len = 0;
    vi intervals_len;
    for (int i = 0; i < n; i++) {
        if (not_available[i]) {
            if (len != 0) intervals_len.push_back(len);
            len = 0;
        } else {
            len++;
        }
    }
    if (len != 0) intervals_len.push_back(len);
    int ans = 0;
    for (int& i : intervals_len) {
        ans += (i + 2) / 3;
    }
    for (bool b : s) {
        if (b) ans++;
    }
    cout << ans << '\n';
}

int main() {
    fio;
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
}
