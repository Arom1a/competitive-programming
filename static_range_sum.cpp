// https://judge.yosupo.jp/problem/static_range_sum

#include "bits/stdc++.h"

typedef long long ll;
using namespace std;

void print_vector(const vector<ll> &my_vec)
{
    for (auto &i : my_vec)
    {
        cout << i << ' ';
    }
    cout << '\n';
}

int main()
{
    // input
    int N, Q;
    cin >> N >> Q;
    vector<ll> a(N+1);
    ll sum = 0;
    for (int i = 0; i < N; i++)
    {
        ll tmp;
        cin >> tmp;
        sum += tmp;
        a[i+1] = sum;
    }
    while (Q--)
    {
        int l, r;
        cin >> l >> r;
        ll ans = a[r] - a[l];
        cout << ans << '\n';
    }

    // test
    // int N = ;
    // vector<int> c{};
    // expected:
}
