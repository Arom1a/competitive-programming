// https://cses.fi/problemset/task/1622

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
    string s;
    cin >> s;
    sort(s.begin(), s.end());
    int count = 0;
    string ans = "";
    do {
        ans += s + '\n';
        count++;
    } while (next_permutation(s.begin(), s.end()));
    cout << count << '\n' << ans;
}
