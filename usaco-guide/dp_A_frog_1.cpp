// https://atcoder.jp/contests/dp/tasks/dp_a

#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

int h_d(const int &h1, const int &h2) // height_difference
{
    return (abs(h1 - h2));
}

int main()
{
    int N;
    cin >> N;
    int h_a[N]; // hight_array
    for (int i = 0; i < N; i++)
    {
        cin >> h_a[i];
    }

    vector<int> c(N, 2147483647); // cost
    c[0] = 0;
    for (int i = 0; i < N - 1; i++)
    {
        c[i + 1] = min(c[i + 1], c[i] + h_d(h_a[i], h_a[i + 1]));
        c[i + 2] = min(c[i + 2], c[i] + h_d(h_a[i], h_a[i + 2]));
    }
    c[N - 1] = min(c[N - 1], c[N - 2] + h_d(h_a[N - 2], h_a[N - 1]));

    cout << c[N - 1];
}