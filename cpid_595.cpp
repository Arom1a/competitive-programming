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
    freopen("div7.in", "r", stdin);
    freopen("div7.out", "w", stdout);
    // input
    int N;
    // stringstream ss("7 3 5 1 6 2 14 10"); // test
    // ss >> N;
    cin >> N;
    vector<int> c(N + 1);
    for (int i = 1; i <= N; i++)
    {
        int tmp;
        cin >> tmp;
        // ss >> tmp;
        c[i] = (c[i - 1] + tmp) % 7;
    }

    // test
    // expected: 5

    // answer below
    int ans = 0;

    for (int i = 0; i < N; i++)
        for (int j = i + 1; j <= N; j++)
        {
            // cout << "c.size" << c.size() << '\n'; // debug
            if (c[j] - c[i] == 0)
            {
                // cout << j << ' ' << i << '\n'; // debug
                ans = max(ans, j - i);
            }
        }

    cout << ans << '\n';
}
