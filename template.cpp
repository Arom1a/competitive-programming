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

int N;
vector<int> c(N);

int main()
{
    // input
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> c[i];

    // test
    // int N = ;
    // vector<int> c{};
    // expected:

    // answer below
    int ans = 0;

    cout << ans << '\n';
}
