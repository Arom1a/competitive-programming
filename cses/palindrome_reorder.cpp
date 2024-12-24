// https://cses.fi/problemset/task/1755

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
    vector<int> alphabet(26);
    for (char c : s)
        alphabet[c - 'A']++;
    int odd_count = 0, odd_position;
    string half_ans = "";
    for (int i = 0; i < alphabet.size(); i++) {
        if (alphabet[i] % 2 == 1) {
            odd_position = i;
            odd_count++;
        } else
            for (int j = 0; j < alphabet[i] / 2; j++) {
                half_ans += char('A' + i);
            }
    }
    string ans = "NO SOLUTION";
    if (odd_count == 1) {
        ans = half_ans;
        for (int i = 0; i < alphabet[odd_position]; i++) {
            ans += char('A' + odd_position);
        }
        reverse(half_ans.begin(), half_ans.end());
        ans += half_ans;
    } else if (odd_count == 0) {
        ans = half_ans;
        reverse(half_ans.begin(), half_ans.end());
        ans += half_ans;
    }
    cout << ans << endl;
}
