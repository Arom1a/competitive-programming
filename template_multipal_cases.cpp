#include "bits/stdc++.h"

typedef long long ll;
using namespace std;

template <typename T>
void print_vector(const vector<T> &my_vec)
{
    for (const T &i : my_vec)
        cout << i << ' ';
    cout << endl;
}

int N, Q;
vector<int> c(N);

int main()
{
    // input
    cin >> N >> Q;

    // test
    // vector<int> c{};
    // int Q = 1, N = c.size();
    // expected:

    // answer below
    while (Q--)
    {
        for (int i = 0; i < N; i++)
            cin >> c[i];

        int ans = 0;

        cout << ans << '\n';
    }
}
