#include "bits/stdc++.h"

using namespace std;

int get_index(vector<int> vec, int num)
{
    auto it = find(vec.begin(), vec.end(), num);
    if (it != vec.end())
    {
        int index = it - vec.begin();
        return index;
    }
    else
    {
        return -1;
    }
}

int main()
{
    vector<int> my_vec{1, 2, 3, 4, 5, 6, 7, 8, 9};
    cout << get_index(my_vec, 1) << '\n';
}
