#include "bits/stdc++.h"

typedef long long ll;
using namespace std;

// void print_vector(const vector<> &my_vec)
// {
//     for (auto &i : my_vec)
//     {
//         cout << i << ' ';
//     }
//     cout << '\n';
// }

int main()
{
    // input
    int T;
    cin >> T;
    while (T--)
    {
        int N, K;
        cin >> N;
        vector<string> c(N); // canvas
        for (int i = 0; i < N; i++)
            cin >> c[i];
        cin >> K;
        vector<string> s(K); // stamp
        for (int i = 0; i < K; i++)
            cin >> s[i];

        for (int r = 0; r < N-K+1; r++)
            for (int c = 0; c < N-K+1; c++)
            {

            }
    }

    // test
    int N = ;
    vector<int> c{};
    // expected:

    // answer below
    int ans = 0;

    cout << ans << '\n';
}
