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

void print_ans(vector<int> ans)
{
    if (ans.size() == 0)
        cout << -1;
    else
    {
        cout << ans[0];
        for (int i = 1; i < ans.size(); i++)
            cout << ' ' << ans[i];
    }
}

int main()
{
    int T;
    cin >> T;

    while (T--)
    {
        vector<int> ans;
        int N;
        cin >> N;
        vector<int> ft(N), tc(N); // favor_types, type_counts
        for (int i = 0; i < N; i++)
        {
            cin >> ft[i];
        }

        for (int i : ft)
        {
            tc[i - 1] += 1;
        }

        int id = 1; // index

        for (int i = 0; i < N; i++)
        {
            // cout << "wtf\n"; // debug
            if (tc[i] > 1)
            {
                bool condi = true;
                for (int j = tc[i]; j < 2 * tc[i] && condi; j++)
                {
                    int n = 0;
                    for (int k = 0; k < j - 1; k++)
                    {
                        if (ft[k] == id)
                            n++;
                    }
                    for (int k = 0; k < (N - j + 1); k++)
                    {
                        // cout << n << '\n'; // debug
                        if (k != 0 && ft[k - 1] == id)
                            n--;
                        if (ft[k + j - 1] == id)
                            n++;
                        if (n > j / 2)
                        {
                            if (ans.size() == 0)
                                ans.push_back(id);
                            if (ans.size() != 0)
                                if (ans.back() != id)
                                    ans.push_back(id);
                            // cout << "Pushed\n"; // debug
                            condi = false;
                        }
                    }
                }
            }

            id++;
        }
        print_ans(ans);
        cout << '\n';
    }
}
