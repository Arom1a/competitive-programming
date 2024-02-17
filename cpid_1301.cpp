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
    ll N, K;
    cin >> N >> K;
    vector<ll> c(N);
    for (ll i = 0; i < N; i++)
        cin >> c[i];

    // test
    // vector<ll> c{1, 5, 10, 15, 20};
    // ll N =c.size(), K = 2;
    // expected: 15

    // answer below
    ll ans = 0;

    vector<ll> d(N - 1); // difference
    for (ll i = 0; i < N - 1; i++)
        d[i] = c[i + 1] - c[i];

    // print_vector(d);

    vector<ll> s; // position to split
    s.reserve(N - 1);
    for (ll i = 0; i < N - 1; i++)
        if (d[i] > K + 1)
            s.push_back(i);

    // print_vector(s);

    ll ld = 0; // last day
    if (s.size() != 0)
    {
        for (ll &i : s)
        {
            // cout << i << ' '; // debug
            ans += c[i] - c[ld] + 1 + K;
            // cout << ans << '\n'; // debug
            ld = i+1;
        }
        ans += c.back() - c[s.back() + 1] + 1 + K;
    }
    else
        ans += c.back() - c.front() + 1 + K;
    // cout << '\n'; // debug
    cout << ans << '\n';
}
