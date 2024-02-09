#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <math.h>

using namespace std;

void print_vector(const vector<int> &my_vec)
{
    for (auto i : my_vec)
    {
        cout << i << ' ';
    }
    cout << '\n';
}

int main()
{
    int N;
    cin >> N;
    string c_str;
    cin >> c_str;

    // int N = 10;
    // string c_str = "0110111011111111110";

    int one_counter = 0;
    vector<int> length_vec;
    int max_day = 2147483647;
    vector<int> max_day_vec;
    vector<int> front_end_length_vec;
    if (c_str.find('0') == -1)
    {
        length_vec.push_back(c_str.length());
    }
    else
    {
        if (c_str[0] == '1')
        {
            int one_length = c_str.find('0');
            max_day = min(one_length - 1, max_day);
            c_str = c_str.substr(one_length);
            front_end_length_vec.push_back(one_length);
        }
        if (c_str[c_str.length() - 1] == '1')
        {
            int one_length = c_str.length() - 1 - c_str.rfind('0');
            max_day = min(one_length - 1, max_day);
            c_str = c_str.substr(0, c_str.rfind('0') + 1);
            front_end_length_vec.push_back(one_length);
        }

        for (char c : c_str)
        {
            if (c == '1')
            {
                one_counter++;
            }
            else
            {
                if (one_counter != 0)
                {
                    length_vec.push_back(one_counter);
                }
                one_counter = 0;
            }
        }
    }
    for (auto i : length_vec)
    {
        max_day = min((int)(i - 1) / 2, max_day);
    }
    if (size(front_end_length_vec) != 0)
    {
        for (auto i : front_end_length_vec)
        {
            length_vec.push_back(i);
        }
    }
    int ans = 0;
    if (max_day == 0)
    {
        for (auto i : length_vec)
        {
            ans += i;
        }
    }
    else
    {
        for (auto i : length_vec)
        {
            int tmp = (int)ceil(i / (double)(2 * max_day + 1));
            if (tmp == 0)
                tmp = 1;
            ans += tmp;
        }
    }
    cout << ans;
}
