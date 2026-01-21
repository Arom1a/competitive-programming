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
    ll N, M;
    string d; // direction
    cin >> N >> M >> d;
    vector<ll> m(N); // milk
    for (ll i = 0; i < N; i++)
        cin >> m[i];

    // test
    // string d = "RRRLRRLLR";
    // vector<ll> m{5, 8, 4, 9, 3, 4, 9, 5, 4};
    // ll N = m.size(), M = 5;
    // expected: 2

    // answer below
    ll ans = 0;
    for (ll &i : m)
        ans += i;

    vector<ll> pr(N); // per round
    // print_vector(pr); // debug
    if (d[0] == 'R')
        pr[1] += 1;
    else
        pr[N - 1] += 1;
    for (ll i = 1; i < N - 1; i++)
    {
        if (d[i] == 'R')
            pr[i + 1] += 1;
        else
            pr[i - 1] += 1;
    }
    if (d[N - 1] == 'R')
        pr[0] += 1;
    else
        pr[N - 2] += 1;
    // print_vector(pr); // debug

    vector<ll> zp; // zero position
    zp.reserve(N);
    for (ll i = 0; i < N; i++)
        if (pr[i] == 0)
            zp.push_back(i);
    // print_vector(zp); // debug

    for (ll &i : zp)
    {
        if (d[i] == 'R')
        {
            ll p = i, sum = 0; // position
            while (pr[p] != 2)
            {
                sum += m[p];
                p += 1;
                if (p == N)
                    p = 0;
            }
            ans -= min(sum, M);
        }
        else
        {
            ll p = i, sum = 0; // position
            while (pr[p] != 2)
            {
                sum += m[p];
                p -= 1;
                if (p == -1)
                    p = N - 1;
            }
            ans -= min(sum, M);
        }
    }

    // for (ll &i : zp)
    // {
    //     if (i != 0 && i != N - 1)
    //     {
    //         ll l = m[i - 1], r = m[i + 1];
    //         if (pr[i - 1] != 0)
    //             l = __LONG_LONG_MAX__;
    //         if (pr[i + 1] != 0)
    //             r = __LONG_LONG_MAX__;
    //         cout << "l: " << l << " | r: " << r << '\n'; // debug
    //         ans -= min(min(l, r), M);
    //     }
    //     else if (i == 0)
    //     {
    //         ll l = m[N - 1], r = m[1];
    //         if (pr[N - 1] != 0)
    //             l = __LONG_LONG_MAX__;
    //         if (pr[1] != 0)
    //             r = __LONG_LONG_MAX__;
    //         cout << "l: " << l << " | r: " << r << '\n'; // debug
    //         ans -= min(min(l, r), M);
    //     }
    //     else
    //     {
    //         ll l = m[N - 2], r = m[0];
    //         if (pr[N - 2] != 0)
    //             l = __LONG_LONG_MAX__;
    //         if (pr[0] != 0)
    //             r = __LONG_LONG_MAX__;
    //         cout << "l: " << l << " | r: " << r << '\n'; // debug
    //         ans -= min(min(l, r), M);
    //     }
    // }

    cout << ans << '\n';
}
