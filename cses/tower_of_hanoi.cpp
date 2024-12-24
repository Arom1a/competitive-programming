// https://cses.fi/problemset/task/2165

#include "bits/stdc++.h"

using namespace std;

string move(int former, int latter, int third, int layers) {
    if (layers == 1) return to_string(former) + ' ' + to_string(latter) + '\n';
    return move(former, third, latter, layers - 1)
           + to_string(former) + ' ' + to_string(latter) + '\n'
           + move(third, latter, former, layers - 1);
}

int main() {
    int n;
    cin >> n;
    string ans = move(1, 3, 2, n);
    cout << pow(2, n) - 1 << '\n';
    cout << ans;
}
