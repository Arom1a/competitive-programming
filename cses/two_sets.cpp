#include "bits/stdc++.h"

typedef long long ll;
using namespace std;

int main() {
    ll n;
    cin >> n;
    ll sum = n * (n + 1) / 2;
    if (sum % 2)
        cout << "NO";
    else {
        cout << "YES" << '\n';
        int count = n;
        sum /= 2;
        while (sum > 0) {
            sum -= count;
            count--;
        }
        count++;
        sum += count;
        count++;

        cout << n - count + 2 << '\n';
        cout << sum << '\n';
        for (int i = count; i <= n; i++) cout << i << ' ';
        cout << endl;

        cout << count - 2 << ' ';
        for (int i = 1; i < sum; i++) cout << i << ' ';
        cout << '\n';
        for (int i = sum + 1; i < count; i++) cout << i << ' ';
    }
}
