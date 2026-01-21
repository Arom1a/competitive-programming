#include "bits/stdc++.h"

typedef long long ll;
using namespace std;

// void print_vector(const vector<> &my_vec)
// {
//     for (auto &i : my_vec)
//     {
//         cout << i << ' ';
//     }
//     cout << '\n';
// }

int main()
{
    // input
    ll N, T;
    cin >> N >> T;

    // test
    // int N = ;
    // vector<int> c{};
    // expected:

    // answer below
    ll ans = 0;
    ll d, o; // day, offer
    cin >> d >> o;
    ll hb = o; // haybale
    for (ll i = 0; i < N - 1; i++)
    {
        ll ld = d; // last day
        cin >> d >> o;
        ans += min(d - ld, hb);
        hb -= min(d - ld, hb);
        hb += o;
    }
    ll ld = d;
    d = T;
    o = 0;
    ans += min(d - ld + 1, hb);

    cout << ans << '\n';
}
