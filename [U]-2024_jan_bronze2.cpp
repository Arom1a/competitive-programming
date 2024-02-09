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
    // Input
    int N, S;
    cin >> N >> S;
    vector<int> q(N);
    vector<int> v(N);
    int tmp;
    for (int i = 0; i < N; i++)
    {
        cin >> tmp;
        q[i] = tmp;
        cin >> tmp;
        v[i] = tmp;
    }

    // Answer
    int position = S - 1;
    int right = 1, power = 1;
    vector<int> track(N);
    while (position >= 0 && position < N)
    {
        if (q[position] == 0)
        {
            // cout << "Meet a jumppad at position " << position << '\n'; // dubug
            right = -right;
            power += v[position];
        }
        else if (q[position] == 1)
        {
            // cout << "Meet a target at position " << position << '\n'; // dubug
            if (power >= v[position] && track[position] == 0)
            {
                // cout << "Break a target at position " << position << '\n'; // dubug
                track[position] = 1;
            }
        }
        position += right * power;
        // cout << "Land on position " << position << '\n'; // debug
    }
    int sum = 0;
    for (int &i : track)
        sum += i;
    cout << sum << '\n';
}
