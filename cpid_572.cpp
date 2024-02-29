#include "bits/stdc++.h"

typedef long long ll;
using namespace std;

void print_vector(const vector<int> &my_vec)
{
    for (auto &i : my_vec)
    {
        cout << i << ' ';
    }
    cout << '\n';
}

// // test
// int N = ;
// vector<int> c{};
// // expected:

int main()
{
    freopen("bcount.in", "r", stdin);
    freopen("bcount.out", "w", stdout);
    // input
    int N, Q;
    cin >> N >> Q;
    array<vector<int>, 3> HGJ;
    for (vector<int> &i : HGJ)
        i = vector<int>(N + 1);
    vector<int> H(N + 1), G(N + 1), J(N + 1);
    for (int i = 1; i <= N; i++)
    {
        int tmp;
        cin >> tmp;
        // cout << "tmp: " << tmp << '\n'; // debug
        HGJ[0][i] = HGJ[0][i - 1];
        HGJ[1][i] = HGJ[1][i - 1];
        HGJ[2][i] = HGJ[2][i - 1];
        if (tmp == 1)
            HGJ[0][i]++;
        else if (tmp == 2)
            HGJ[1][i]++;
        else
            HGJ[2][i]++;
    }

    while (Q--)
    {
        int ans1 = 0, ans2 = 0, ans3 = 0;
        int a, b;
        cin >> a >> b;
        ans1 = HGJ[0][b] - HGJ[0][a - 1];
        ans2 = HGJ[1][b] - HGJ[1][a - 1];
        ans3 = HGJ[2][b] - HGJ[2][a - 1];

        cout << ans1 << ' ' << ans2 << ' ' << ans3 << '\n';
    }
}
