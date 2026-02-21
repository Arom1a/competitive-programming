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
    string in;
    cin >> in;

    int cnt[26];
    for (int& i : cnt) {
        i = 0;
    }
    int diff = 0;
    bool conseq = 0;
    for (int i = 0; i < n - 1; i++) {
        if (in[i] != in[i + 1]) {
            diff += 1;
        }
        if (in[i] == in[i + 1]) {
            conseq = 1;
        }
        cnt[in[i] - 97] += 1;
    }
    cnt[in[n - 1] - 97] += 1;
    diff += 1;

    if (in[0] != in[n - 1] && conseq) diff += 1;

    cout << diff << '\n';
}

int main() {
    fio;
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
}
