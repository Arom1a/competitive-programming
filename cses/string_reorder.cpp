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

const int CHARLEN = 30;

bool endwith(const string& str, char c) {
    if (str.size() == 0) {
        return false;
    }
    if (str[str.size() - 1] != c) {
        return false;
    }
    return true;
}

void solve() {
    string in;
    cin >> in;
    int m[CHARLEN] = {0};
    int n = 0;
    for (char c : in) {
        m[c - 'A'] += 1;
        n += 1;
    }

    string ans = "";
    while (n) {
        int impossible = (n + 1) / 2;
        for (int i = 0; i < CHARLEN; i++) {
            if (m[i] > impossible) {
                cout << "-1\n";
                return;
            }
        }

        int force = n / 2;
        int force_idx = -1;
        for (int i = 0; i < CHARLEN; i++) {
            if (m[i] > force) {
                force_idx = i;
                break;
            }
        }

        if (force_idx != -1) {
            if (endwith(ans, force_idx + 'A')) {
                cout << "-1\n";
                return;
            }
            ans += (char)(force_idx + (int)'A');
            m[force_idx] -= 1;
        } else {
            bool flag = 0;
            for (int i = 0; i < CHARLEN; i++) {
                if (m[i] > 0 && !endwith(ans, i + 'A')) {
                    ans += (char)(i + (int)'A');
                    m[i] -= 1;
                    flag = 1;
                    break;
                }
            }
            if (!flag) {
                cout << "-1\n";
                return;
            }
        }
        n--;
    }

    cout << ans << '\n';
}

int main() {
    fio;
    int T = 1;
    while (T--) {
        solve();
    }
}
