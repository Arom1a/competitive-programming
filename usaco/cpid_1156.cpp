#include "bits/stdc++.h"

using namespace std;

void print_vector(const vector<int> &my_vec)
{
    for (auto i : my_vec)
    {
        cout << i << ' ';
    }
    cout << '\n';
}

int main()
{
    // input
    int N;
    cin >> N;
    vector<int> c_t(N), c_n(N), c(N); // cow_temp, cow_now
    for (int i = 0; i < N; i++)
        cin >> c_t[i];
    for (int i = 0; i < N; i++)
        cin >> c_n[i];
    for (int i = 0; i < N; i++)
        c[i] = c_t[i] - c_n[i];

    // test
    // vector<int> c{3, -2, -1, -1, 1, 0, -1, 1, 3};
    // int N = c.size();

    // answer below
    int fn = 0; // first_nonzero
    int ans = 0;

    while (true)
    {
        while (fn < N && c[fn] == 0)
            fn++;
        if (fn == N)
            break;
        int end = N;
        for (int i = fn; i < N; i++)
        {
            if (c[fn] > 0)
                if (c[i] < 1)
                {
                    end = i;
                    break;
                }
            if (c[fn] < 0)
                if (c[i] > -1)
                {
                    end = i;
                    break;
                }
        }
        // cout << fn << ' ' << end << '\n'; // debug
        vector<int> cp(c.begin() + fn, c.begin() + end);
        for (int &i : cp)
            i = abs(i);
        int min = *min_element(cp.begin(), cp.end());
        // cout << min << '\n'; // debug
        // cout << "abs(min) " << abs(min) << '\n'; // debug
        ans += abs(min);
        for (int i = fn; i < end; i++)
        {
            // cout << c[i] << '\n'; // debug
            // cout << c[fn] << '\n'; // debug
            if (c[i] > 0)
                c[i] -= min;
            else
                c[i] += min;
        }
        // print_vector(c); // debug
    }

    cout << ans << '\n';
}
