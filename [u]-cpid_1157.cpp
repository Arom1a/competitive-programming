#include "bits/stdc++.h"

using namespace std;

void print_2dvector(const vector<vector<int>> &my_vec)
{
    for (auto &i : my_vec)
    {
        for (auto &j : i)
            cout << j << ' ';
        cout << '\n';
    }
}

int k1(const vector<vector<int>> &map)
{
    int n = map.size();
    int ans;
    int t_r = 1, l_b = 1; // top_right, left_bottom
    for (int i = 0; i < n; i++)
        if (map[0][i] == 1)
        {
            t_r = 0;
            break;
        }
    for (int i = 0; i < n; i++)
        if (map[n - 1][i] == 1)
        {
            l_b = 0;
            break;
        }
    for (int i = 0; i < n; i++)
        if (map[i][n - 1] == 1)
        {
            t_r = 0;
            break;
        }
    for (int i = 0; i < n; i++)
        if (map[i][0] == 1)
        {
            l_b = 0;
            break;
        }
    ans = t_r + l_b;
    return ans;
}

int k2(const vector<vector<int>> &map)
{
    int n = map.size();
    int ans = 0;
    vector<int> t_r(n - 2, 1), l_b(n - 2, 1); // top_right, left_bottom
    for (int i = 1; i < n - 1; i++)
    {
        vector<int> check(n);
        for (int j = 0; j < n; j++)
            check[j] = map[i][j];
        if (find(check.begin(), check.end(), 1) != check.end())
        {
            t_r[i - 1] = 0;
            continue;
        }
    }
    for (int i = 1; i < n - 1; i++)
    {
        vector<int> check(n);
        for (int j = 0; j < i; j++)
            check[j] = map[0][j];
        if (find(check.begin(), check.end(), 1) != check.end())
        {
            t_r[i - 1] = 0;
            continue;
        }
    }
    for (int i = 1; i < n - 1; i++)
    {
        vector<int> check(n);
        for (int j = i + 1; j < n; j++)
            check[j] = map[n - 1][j];
        if (find(check.begin(), check.end(), 1) != check.end())
        {
            t_r[i - 1] = 0;
            continue;
        }
    }

    for (int i = 1; i < n - 1; i++)
    {
        vector<int> check(n);
        for (int j = 0; j < n; j++)
            check[j] = map[j][i];
        if (find(check.begin(), check.end(), 1) != check.end())
        {
            l_b[i - 1] = 0;
            continue;
        }
    }
    for (int i = 1; i < n - 1; i++)
    {
        vector<int> check(n);
        for (int j = 0; j < i; j++)
            check[j] = map[j][0];
        if (find(check.begin(), check.end(), 1) != check.end())
        {
            l_b[i - 1] = 0;
            continue;
        }
    }
    for (int i = 1; i < n - 1; i++)
    {
        vector<int> check(n);
        for (int j = i + 1; j < n; j++)
            check[j] = map[j][n - 1];
        if (find(check.begin(), check.end(), 1) != check.end())
        {
            l_b[i - 1] = 0;
            continue;
        }
    }
    for (int &i : t_r)
    {
        // cout << i << '\n'; // debug
        ans += i;
    }
    for (int &i : l_b)
    {
        // cout << i << '\n'; // debug
        ans += i;
    }
    return ans;
}

int k3(const vector<vector<int>> &map)
{
    int n = map.size();
    int ans = 0;
    vector<vector<int>> t_r(n - 2, vector<int>(n - 2, 1)), l_b(n - 2, vector<int>(n - 2, 1));
    vector<int> check(n);
    for (int i = 1; i < n - 1; i++)
        for (int j = 1; j < n - 1; j++)
        {
            fill(check.begin(), check.end(), 0);
            for (int a = 0; a < i; a++)
                check[a] = map[0][a];
            if (find(check.begin(), check.end(), 1) != check.end())
            {
                t_r[i - 1][j - 1] = 0;
                continue;
            }
            fill(check.begin(), check.end(), 0);
            for (int a = 0; a < j; a++)
                check[a] = map[a][i];
            if (find(check.begin(), check.end(), 1) != check.end())
            {
                t_r[i - 1][j - 1] = 0;
                continue;
            }
            fill(check.begin(), check.end(), 0);
            for (int a = i; a < n; a++)
                check[a] = map[j][a];
            if (find(check.begin(), check.end(), 1) != check.end())
            {
                t_r[i - 1][j - 1] = 0;
                continue;
            }
            fill(check.begin(), check.end(), 0);
            for (int a = j; a < n; a++)
                check[a] = map[a][n - 1];
            if (find(check.begin(), check.end(), 1) != check.end())
            {
                t_r[i - 1][j - 1] = 0;
                continue;
            }
        }

    for (int i = 1; i < n - 1; i++)
        for (int j = 1; j < n - 1; j++)
        {
            fill(check.begin(), check.end(), 0);
            for (int a = 0; a < j; a++)
                check[a] = map[a][0];
            if (find(check.begin(), check.end(), 1) != check.end())
            {
                l_b[i - 1][j - 1] = 0;
                continue;
            }
            fill(check.begin(), check.end(), 0);
            for (int a = 0; a < i; a++)
                check[a] = map[j][a];
            if (find(check.begin(), check.end(), 1) != check.end())
            {
                l_b[i - 1][j - 1] = 0;
                continue;
            }
            fill(check.begin(), check.end(), 0);
            for (int a = j; a < n; a++)
                check[a] = map[a][i];
            if (find(check.begin(), check.end(), 1) != check.end())
            {
                l_b[i - 1][j - 1] = 0;
                continue;
            }
            fill(check.begin(), check.end(), 0);
            for (int a = i; a < n; a++)
                check[a] = map[n - 1][a];
            if (find(check.begin(), check.end(), 1) != check.end())
            {
                l_b[i - 1][j - 1] = 0;
                continue;
            }
        }

    for (vector<int> &i : t_r)
        for (int &j : i)
            ans += j;
    for (vector<int> &i : l_b)
        for (int &j : i)
            ans += j;
    return ans;
}

int main()
{
    // input
    int T;
    cin >> T;
    while (T--)
    {
        int N, K;
        cin >> N >> K;
        string tmp;
        vector<vector<int>> map(N, vector<int>(N));
        for (int i = 0; i < N; i++)
        {
            cin >> tmp;
            for (int j = 0; j < N; j++)
            {
                if (tmp[j] == '.')
                    map[i][j] = 0;
                else
                    map[i][j] = 1;
            }
        }

        int ans;
        if (K == 1)
            ans = k1(map);
        else if (K == 2)
            ans = k1(map) + k2(map);
        else if (K == 3)
            ans = k1(map) + k2(map) + k3(map);

        cout << ans << '\n';
        // test
        // int N = 3;
        // vector<vector<int>> map{{1, 0, 0}, {0, 1, 0}, {0, 0, 0}};
        // expected:
        // cout << k1(map) << '\n';
        // cout << k2(map) << '\n';
        // cout << k3(map) << '\n';

        // answer below
        // int ans = 0;

        // cout << ans << '\n';
    }
}
