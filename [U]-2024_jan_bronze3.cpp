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

int main()
{
    int N;
    cin >> N;
    vector<long long> gl(N); // grass_line
    for (int i=0; i<N; i++)
    {
        cin >> gl[i];
    }
    reverse(gl.begin(), gl.end());

    long long ans=0;
    for (int i=0; i<N; i++)
    {
        int length=gl.size(), back=gl.back();
        ans += abs(back);
        gl.pop_back();
        for (int i=0; i < length-1; i++)
        {
            gl[i] -= back*(length-i);
        }
    }
    cout << ans << '\n';
}
