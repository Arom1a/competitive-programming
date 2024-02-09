#include "bits/stdc++.h"

using na

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
    int T;
    cin >> T;

    while(T--)
    {
        vector<int> ans;
        int N;
        cin >> N;
        vector<int> ft(N); // favor_types, type_counts
        for (int i = 0; i < N; i++)
        {
            cin >> ft[i];
        }

        for (int i=0; i < N;i++)
        {
            int type=i+1;
            vector<int>::iterator it;
            it = find(ft.begin(), ft.end(), type);

        }
    }
}
