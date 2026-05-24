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

unordered_set<char> cal_union(unordered_set<char> a, unordered_set<char> b) {
    unordered_set<char> tgt;
    for (char c : a) {
        if (b.find(c) != b.end()) {
            tgt.insert(c);
        }
    }
    return tgt;
}

void solve() {
    int n, k;
    cin >> n >> k;
    vs ss(k);
    for (int i = 0; i < k; i++) {
        cin >> ss[i];
    }

    vec<unordered_set<char>> letter_sets(n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < k; j++) {
            letter_sets[i].insert(ss[j][i]);
        }
    }

    for (int l = 1; l < n; l++) {
        string minimal = "";
        if (n % l != 0) continue;

        bool flag = 0;
        for (int i = 0; i < l; i++) {
            unordered_set<char> build = cal_union(letter_sets[i], letter_sets[i + l]);
            if (build.size() == 0) {
                flag = 1;
                break;
            }
            for (int j = 2; j < n / l; j++) {
                build = cal_union(build, letter_sets[i + j * l]);
                if (build.size() == 0) {
                    flag = 1;
                    break;
                }
            }
            if (flag) break;
            minimal.push_back(*build.begin());
        }
        if (flag) continue;

        string ans = "";
        for (int i = 0; i < n / l; i++) {
            ans += minimal;
        }
        cout << ans << '\n';
        return;
    }
    cout << ss[0] << '\n';
}

int main() {
    fio;
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
}
