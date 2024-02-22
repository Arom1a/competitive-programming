#include "bits/stdc++.h"

typedef long long ll;
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
    int N, Q;
    cin >> N >> Q;
    vector<int> c(N);
    for (int i = 0; i < N; i++)
        cin >> c[i];
    vector<int> t(N);
    for (int i = 0; i < N; i++)
        cin >> t[i];

    // test
    // int N = ;
    // vector<int> c{};
    // expected:

    // answer below

    vector<int> d(N);
    for (int i = 0; i < N; i++)
        d[i] = c[i] - t[i];
    sort(d.begin(), d.end());
    // print_vector(d); // debug

    while (Q--)
    {
        int V, S;
        cin >> V >> S;

        // cout << "d[N-V] : " << d[N - V] << " | S : " << S << '\n'; // debug
        string ans = d[N - V] > S ? "YES" : "NO";

        // cout << "count: " << count << '\n';
        // string ans = count >= V ? "YES" : "NO";
        cout << ans << '\n';
    }
}
