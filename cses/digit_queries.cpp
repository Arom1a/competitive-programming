// https://cses.fi/problemset/task/2431/
// #math
// lesson: using the pow() function will cause a hugh problem when dealing with large numbers!!!

#include "bits/stdc++.h"
#define all(a) a.begin(), a.end()

typedef long long ll;
using namespace std;

template <typename T>
void print_vector(const vector<T> &my_vec) {
    for (const T &i : my_vec)
        cout << i << ' ';
    cout << endl;
}

int main() {
    int q;
    cin >> q;
    string ans = "";
    while (q--) {
        ll k;
        cin >> k;
        ll digit = 1, curr = 0, c = 1;
        while (k > digit * 9 * c) {
            k -= digit * 9 * c;
            digit++;
            curr = curr * 10 + 9;
            c *= 10;
        }
        // cout << "k: " << k << " | digit: " << digit << '\n';  // debug
        ll plus = k / digit, posi = k % digit;
        // cout << "plus: " << plus << " | posi: " << posi << '\n';  // debug
        ll nines = 0;
        for (int i = 0; i < digit - 1; i++)
            nines = nines * 10 + 9;
        string ans_str = to_string(nines + plus).back() + to_string(nines + plus + 1);
        cout << ans_str[posi] << '\n';
    }
}
