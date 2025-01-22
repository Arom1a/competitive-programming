// https://cses.fi/problemset/task/1640
// #sort and search, #two pointers
// lesson: binary_search is better than find

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

// int main() {
//     fio;
//
//     int n, x;
//     cin >> n >> x;
//     vector<int> a(n);
//     for (int i = 0; i < n; i++)
//         cin >> a[i];
//
//     vector<int> ac(a.begin(), a.end());
//     sort(ac.begin(), ac.end());
//
//     for (int i = 0; i < n; i++) {
//         if (binary_search(ac.begin() + i + 1, ac.end(), x - ac[i])) {
//             auto it1 = find(a.begin(), a.end(), ac[i]);
//             *it1 = -1;
//             auto it2 = find(a.begin(), a.end(), x - ac[i]);
//             cout << distance(a.begin(), it1) + 1 << ' ' << distance(a.begin(), it2) + 1 << endl;
//             goto END;
//         }
//     }
//
//     cout << "IMPOSSIBLE\n";
//
// END:
//     return 0;
// }

int main() {
    fio;
    int n, x;
    cin >> n >> x;
    vector<pair<int, int>> a;
    for (int i = 0; i < n; i++) {
        int a_i;
        cin >> a_i;
        a.push_back(mp(a_i, i + 1));
    }

    sort(a.begin(), a.end());
    int l = 0, r = n - 1;
    while (l < r) {
        int s = a[l].f + a[r].f;
        if (s > x) {
            r--;
        } else if (s < x) {
            l++;
        } else {
            cout << a[l].s << ' ' << a[r].s << '\n';
            return 0;
        }
    }

    cout << "IMPOSSIBLE\n";
}
