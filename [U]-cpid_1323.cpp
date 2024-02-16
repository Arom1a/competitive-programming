#include "bits/stdc++.h"

using namespace std;

void print_vector(const vector<int> &my_vec)
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
    // int N;
    // cin >> N;
    // string msg;
    // cin >> msg;

    // test
    string msg = "BFFFFFEBFE";
    int N = msg.size();
    // expected: 2
    //           1
    //           2

    // bel: 10  o_c: 0  t_c: 2
    // 10, 12, 14
    // t_c + 1

    // bel: 10  o_c: 1  t_c: 2
    // 10, 11, 12, 13, 14, 15
    // bel: 10  o_c: 2  t_c: 2
    // 10, 11, 12, 13, 14, 15, 16
    // t_c *2 + 1 + o_c

    // answer below
    int ans = 0;
    int bel = 0;          // base excitement level
    int o_c = 0, t_c = 0; // one_count, two_count
    vector<int> F_p;      // F_position
    for (int i = 0; i < N; i++)
        if (msg[i] == 'F')
            F_p.push_back(i);
    // print_vector(F_p); // debug
    for (int i = 0; i < N - 1; i++)
        if (msg[i] == msg[i + 1])
            bel += 1;
    for (int &i : F_p)
    {
        if (i != 0 && i != N - 1)
        {
            // cout << "why" << '\n'; // debug
            if (msg[i - 1] != msg[i + 1])
                bel++;
            else
                t_c++;
        }
        else
            o_c++;
    }
    if (o_c == 0)
        ans = t_c + 1;
    else
        ans = t_c * 2 + 1 + o_c;

    cout << ans << '\n';
    // cout << "bel: " << bel << " | o_c: " << o_c << " | t_c: " << t_c << '\n'; // debug

    if (o_c == 0)
        for (int i = bel; i <= bel + 2 * t_c; i += 2)
            cout << i << '\n';
    else
        for (int i = bel; i <= bel + 2 * t_c + o_c; i++)
            cout << i << '\n';
}
