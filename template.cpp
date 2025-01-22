#include "bits/stdc++.h"

using namespace std;
#define all(a) a.begin(), a.end()
#define fio                  \
    ios::sync_with_stdio(0); \
    cin.tie(NULL)
#define f first
#define s second
#define mp make_pair
typedef long long ll;
typedef vector<int> vi;

template <typename T>
void print_1dvec(const vector<T> &vec) {
    for (const T &i : vec)
        cout << i << ' ';
    cout << '\n';
}

template <typename T>
void print_2dvec(const vector<vector<T>> &vec) {
    for (const vector<T> &i : vec) {
        for (const T &j : i) {
            cout << j << ' ';
        }
        cout << '\n';
    }
}

int main() {
    fio;

    int n;
    cin >> n;
    vector<int> c(n);
    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }

    int ans = 0;
    cout << ans << '\n';
}
