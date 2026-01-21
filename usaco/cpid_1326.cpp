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

int main()
{
    // input
    cin >> N;
    vector<ll> a(N);
    for (int i = 0; i < N; i++)
        cin >> a[i];
    cin >> Q;

    // test
    // vector<int> a{1, 10, 4, 2, 6};
    // int Q = 1, N = a.size();
    // int index = 4, j = 5;
    // expected:

    vector<ll> sa(a); // sorted_a
    sort(sa.begin(), sa.end(), [](int a, int b)
         { return a < b; });
    vector<ll> ss(N + 1); // suffix_sum
    partial_sum(sa.rbegin(), sa.rend(), ss.rbegin() + 1);

    // print_vector(sa); // debug
    // print_vector(ss); // debug

    ll ori_value = 0;
    for (int i = 0; i < N; i++)
        ori_value += (i + 1) * sa[i];

    // answer below
    while (Q--)
    {
        int index;
        ll j;
        cin >> index >> j;
        index--;
        ll ans = ori_value;
        int old_index = lower_bound(sa.begin(), sa.end(), a[index]) - sa.begin();
        int new_index = lower_bound(sa.begin(), sa.end(), j) - sa.begin();

        ll deletion = (old_index + 1) * a[index], addition = (new_index + 1) * j;

        ans = ans - deletion + addition;

        if (old_index > new_index)
            ans += ss[new_index] - ss[old_index];
        else if (old_index < new_index)
            ans -= j + ss[old_index + 1] - ss[new_index];

        cout << ans << '\n';
    }
}
