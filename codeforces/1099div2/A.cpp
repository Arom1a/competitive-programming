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

    int num = 1;
    unordered_set<int> ele_set;
    vec<int> gen;
    gen.reserve(n);
    gen.push_back(1);
    ele_set.insert(1);
    int num_gen = 1;

    while (num <= 2 * n) {
        if (ele_set.find(num) == ele_set.end() && ele_set.find(num + gen.back()) == ele_set.end()) {
            int last = gen.back();
            gen.push_back(num);
            ele_set.insert(num);
            ele_set.insert(last + num);
            num_gen += 1;
        }

        if (num_gen == n) {
            break;
        }
        num += 1;
    }

    for (int i : gen) {
        cout << i << ' ';
    }
    cout << endl;
}

int main() {
    fio;
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
}
