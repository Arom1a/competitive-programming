#include <bits/stdc++.h>

using namespace std;
#define all(a) a.begin(), a.end()
#define fio                  \
    ios::sync_with_stdio(0); \
    cin.tie(NULL)
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vll;

void solve(int t) {
    string drop;
    cin >> drop;
    int t_cp = t;
    while (t--) {
        for (int i = 1; i <= t; i++) {
            cout << "? " << i << ' ' << i + 1 << '\n';
        }
    }

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> d(1, t_cp - 1);
    int random_num = d(gen);

    cout << "! " << random_num << ' ' << random_num + 1 << '\n';
}

int main() {
    fio;

    int T;
    cin >> T;
    for (int t = 0; t < T; t++) {
        solve(t + 2);
    }
}
