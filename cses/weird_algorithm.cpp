// https://cses.fi/problemset/task/1068

#include "bits/stdc++.h"

typedef long long ll;
using namespace std;

void recur(ll n) {
    cout << n << ' ';
    if (n == 1) return;
    if (n % 2 == 0) recur(n / 2);
    if (n % 2 == 1) recur(n * 3 + 1);
}

int main() {
    ll n;
    cin >> n;
    recur(n);
    cout << endl;
}
