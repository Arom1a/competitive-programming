#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <numeric>
#include <set>
#include <array>

using namespace std;

void print_vector(vector<long> my_vec)
{
    for (auto i : my_vec)
    {
        cout << i << ' ';
    }
    cout << '\n';
}

int solve(vector<long> h_i, vector<long> h_g, vector<long> n_p)
{
    vector<long> sorted_h_i(size(h_i));
    vector<long> sorted_h_g(size(h_g));
    std::vector<int> indices(n_p.size());
    std::iota(indices.begin(), indices.end(), 0);
    std::sort(indices.begin(), indices.end(), [n_p](int a, int b)
              { return n_p[a] > n_p[b]; });
    for (size_t i = 0; i < indices.size(); ++i)
    {
        sorted_h_i[i] = h_i[indices[i]];
    }
    for (size_t i = 0; i < indices.size(); ++i)
    {
        sorted_h_g[i] = h_g[indices[i]];
    }

    sort(n_p.begin(), n_p.end(), [](int a, int b)
         { return a > b; });
    int day = 0;
    while (1)
    {
        for (int i = 0; i < size(sorted_h_i); i++)
            for (int j = i + 1; j < size(sorted_h_i); j++)
            {
                if (sorted_h_i[i] >= sorted_h_i[j] & sorted_h_g[i] >= sorted_h_g[j])
                {
                    day = -1;
                    return day;
                }
            }
        vector<long> copy_h_i(sorted_h_i.begin(), sorted_h_i.end());
        set<long> set_copy_h_i(copy_h_i.begin(), copy_h_i.end());
        if (size(copy_h_i) == 1 | size(set_copy_h_i) != 1)
        {
            sort(copy_h_i.begin(), copy_h_i.end());
            if (copy_h_i == sorted_h_i)
            {
                return day;
            }
        }
        for (int k = 0; k < size(sorted_h_i); k++)
        {
            sorted_h_i[k] += sorted_h_g[k];
        }
        day++;
    }
    cout << day;
}

int main()
{
    int T;
    cin >> T;
    vector<array<vector<long>, 3>> cases(T);
    for (int i = 0; i < T; i++)
    {
        int N;
        cin >> N;
        vector<long> h_i(N); // initial_height
        for (int i = 0; i < N; i++)
        {
            long tmp;
            cin >> tmp;
            h_i[i] = tmp;
        }
        vector<long> h_g(N); // grow_height
        for (int i = 0; i < N; i++)
        {
            long tmp;
            cin >> tmp;
            h_g[i] = tmp;
        }
        vector<long> n_p(N); // number of plant that exceeds
        for (int i = 0; i < N; i++)
        {
            long tmp;
            cin >> tmp;
            n_p[i] = tmp;
        }
        array<vector<long>, 3> tmp_arr = {h_i, h_g, n_p};
        cases[i] = tmp_arr;
    }
    for (auto i : cases)
    {
        cout << solve(i[0], i[1], i[2]) << '\n';
    }
}
