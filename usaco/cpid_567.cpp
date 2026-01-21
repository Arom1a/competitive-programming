#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    freopen("paint.in", "r", stdin);
    freopen("paint.out", "w", stdout);

    int ans;
    int j[2];
    int b[2];

    cin >> j[0] >> j [1];
    cin >> b[0] >> b[1];

    int len_j = j[1] - j[0];
    int len_b = b[1] - b[0];

    int longer[2];
    int shotter[2];
    if (len_j > len_b)
    {
        for (int i=0; i<2; i++)
        {
            longer[i] = j[i];
            shotter[i] = b[i];
        }
    } else
    {
        for (int i=0; i<2; i++)
        {
            longer[i] = b[i];
            shotter[i] = j[i];
        }
    }

    if (longer[1] < shotter[0] | longer[0] > shotter[1])
    {
        ans = len_j + len_b;
    } else if ((longer[1] >= shotter[0] & longer[1] <= shotter[1]) | (longer[0] >= shotter[0] & longer[0] <= shotter[1]))
    {
        ans = max({j[0], j[1], b[0], b[1]}) - min({j[0], j[1], b[0], b[1]});
    } else
    {
        ans = max({len_j, len_b});
    }

    cout << ans << "\n";
}