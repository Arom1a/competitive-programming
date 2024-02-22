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

ll calculate_intercept(ll x, ll y, ll slope)
{
    return y - x * slope;
}

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        // input
        int N;
        ll X_1;
        cin >> N >> X_1;
        vector<ll> Y_1(N), Y_2(N), X_2(N);
        for (int i = 0; i < N; i++)
            cin >> Y_1[i] >> Y_2[i] >> X_2[i];
        vector<ll> s_n, s_p; // s_negative, s_positive
        s_n.reserve(4 * N);
        s_p.reserve(4 * N);
        for (int i = 0; i < 4 * N; i++)
        {
            ll tmp;
            cin >> tmp;
            if (tmp < 0)
                s_n.push_back(tmp);
            else
                s_p.push_back(tmp);
        }

        sort(s_n.begin(), s_n.end(), greater<ll>());
        sort(s_p.begin(), s_p.end());
        // print_vector(s_n); // debug
        // print_vector(s_p); // debug
        vector<int> indices(N);
        iota(indices.begin(), indices.end(), 0);
        sort(indices.begin(), indices.end(), [&X_2](int left, int right)
             { return X_2[left] > X_2[right]; });
        vector<ll> sorted_Y1(N), sorted_Y2(N);
        for (int i = 0; i < N; i++)
        {
            sorted_Y1[i] = Y_1[indices[i]];
            sorted_Y2[i] = Y_2[indices[i]];
        }
        sort(X_2.begin(), X_2.end(), greater<ll>());
        // print_vector(sorted_Y1); // debug
        // print_vector(X_2);       // debug
        // print_vector(sorted_Y2); // debug
        for (int i = 0; i < N - 1; i++)
        {
            if (X_2[i] == X_2[i + 1])
            {
                // cout << "wtf\n"; // debug
                int p = i;
                while (i < N && X_2[i] == X_2[p])
                    p++;
                // cout << "p: " << p << '\n'; // debug
                // cout << *min_element(sorted_Y1.begin() + i, sorted_Y1.begin() + p) << '\n'; // debug
                // cout << *max_element(sorted_Y2.begin() + i, sorted_Y2.begin() + p) << '\n'; // debug
                ll tmp_Y1 = sorted_Y1[i], tmp_Y2 = sorted_Y2[i];
                auto min_p = min_element(sorted_Y1.begin() + i, sorted_Y1.begin() + p), max_p = max_element(sorted_Y2.begin() + i, sorted_Y2.begin() + p);
                // cout << "asdf: " << *min_p << ' ' << *max_p << '\n'; // debug
                sorted_Y1[i] = *min_p;
                sorted_Y2[i] = *max_p;
                *min_p = tmp_Y1;
                *max_p = tmp_Y2;
            }
        }
        // print_vector(sorted_Y1); // debug
        // print_vector(X_2);       // debug
        // print_vector(sorted_Y2); // debug

        ll ans = 0;
        if (s_n.size() >= N && s_p.size() >= N)
        {
            ll t = 0, b = 0; // top, bottom
            for (int i = 0; i < N; i++)
            {
                ll t_tmp = calculate_intercept(X_2[i], sorted_Y2[i], s_n[i]), b_tmp = calculate_intercept(X_2[i], sorted_Y1[i], s_p[i]);
                // cout << X_2[i] << ' ' << sorted_Y2[i] << ' ' << s_n[i] << '\n'; // debug
                // cout << "t_tmp: " << t_tmp << " | b_tmp: " << b_tmp << '\n'; // debug
                if (t_tmp > t)
                    t = t_tmp;
                if (b_tmp < b)
                    b = b_tmp;
            }
            // cout << "t: " << t << " | b: " << b << '\n'; // debug
            ans = t - b;
        }
        else
            ans = -1;

        cout << ans << '\n';
    }
}
