#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

bool check(pair<int, int> p1, pair<int, int> p2, pair<int, int> p3)
{
    return (p1.first == p2.first || p2.first == p3.first || p3.first == p1.first) && (p1.second == p2.second || p2.second == p3.second || p3.second == p1.second);
}

int calculate_area(pair<int, int> p1, pair<int, int> p2, pair<int, int> p3)
{
    int x, y;
    if (p1.first == p2.first)
    {
        y = abs(p1.second - p2.second);
        if (p1.second == p3.second)
        {
            x = abs(p1.first - p3.first);
        } else if (p2.second == p3.second)
        {
            x = abs(p2.first - p3.first);
        }
    } else if (p2.first == p3.first)
    {
        y = abs(p2.second - p3.second);
        if (p2.second == p1.second)
        {
            x = abs(p2.first - p1.first);
        } else if (p3.second == p1.second)
        {
            x = abs(p3.first - p1.first);
        }
    } else if (p3.first == p1.first)
    {
        y = abs(p3.second - p1.second);
        if (p3.second == p2.second)
        {
            x = abs(p3.first - p2.first);
        } else if (p1.second == p2.second)
        {
            x = abs(p1.first - p2.first);
        }
    }
    return x*y;
}

int main()
{
    freopen("triangles.in", "r", stdin);
    freopen("triangles.out", "w", stdout);

    int N;
    cin >> N;
    vector<pair<int, int>> d(N); // data
    for (int i = 0; i < N; i++)
    {
        int tmp1, tmp2;
        cin >> tmp1 >> tmp2;
        d[i] = (pair<int, int>){tmp1, tmp2};
    }

    int a;
    int ans = 0; // area

    for (int i = 0; i < N; i++)
    {
        for (int j = i + 1; j < N; j++)
        {
            for (int k = j + 1; k < N; k++)
            {
                if (check(d[i], d[j], d[k]))
                {
                    a = calculate_area(d[i], d[j], d[k]);
                    if (a > ans)
                    {
                        ans = a;
                    }
                }
            }
        }
    }

    cout << ans;
}
