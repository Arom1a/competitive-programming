// http://www.usaco.org/current/data/sol_prob3_bronze_dec23.html

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll ceil_div(ll a, ll b)
{
    return (a + b - 1) / b;
}

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int N;
        cin >> N;
        vector<ll> height(N), add(N), t(N);
        for (ll &i : height)
            cin >> i;
        for (ll &i : add)
            cin >> i;
        for (ll &i : t)
            cin >> i;
        vector<int> p(N);
        for (int i = 0; i < N; i++)
        {
            p[t[i]] = i;
        }
        ll days = 0;
        for (int i = N - 2; i >= 0; i--)
        {
            int small_idx = p[i + 1], big_idx = p[i];
            ll h_diff = (height[small_idx] + add[small_idx] * days) - (height[big_idx] + add[big_idx] * days);
            if (h_diff >= 0)
            {
                ll a_diff = add[big_idx] - add[small_idx];
                if (a_diff <= 0)
                {
                    days = -1;
                    break;
                }
                days += ceil_div(h_diff + 1, a_diff);
            }
        }
        for (int i = N - 2; i >= 0; i--)
        {
            ll big_days = height[p[i]] + add[p[i]] * days;
            ll small_days = height[p[i + 1]] + add[p[i + 1]] * days;
            if (small_days >= big_days)
            {
                days = -1;
                break;
            }
        }
        cout << days << "\n";
    }
}