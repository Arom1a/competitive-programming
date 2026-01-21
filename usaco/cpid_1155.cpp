#include "bits/stdc++.h"

using namespace std;

// void print_vector(const vector<> &my_vec)
// {
//     for (auto i : my_vec)
//     {
//         cout << i << ' ';
//     }
//     cout << '\n';
// }

int main()
{
    // input
    int N;
    cin >> N;
    string c_str;
    cin >> c_str;
    vector<int> c(N); // cows
    // G is 0, H is 1
    for (int i = 0; i < N; i++)
    {
        if (c_str[i] == 'G')
            c[i] = 0;
        else
            c[i] = 1;
    }

    // test
    // int N = 5;
    // vector<int> c{0, 1, 0, 1, 0};
    // expected: 3

    // answer
    long long ans = 0;
    for (int i = 0; i < N; i++)
    {
        long long l = 0, r = 0;
        for (int j = i - 1; j > 0 - 1; j--)
        {
            if (c[j] != c[i])
                l++;
            else
                break;
        }
        for (int j = i + 1; j < N; j++)
        {
            if (c[j] != c[i])
                r++;
            else
                break;
        }
        // cout << l << ' ' << r << '\n'; // debug
        ans += l * r + max(l - 1, (long long)0) + max(r - 1, (long long)0);
    }
    cout << ans << '\n';
}
