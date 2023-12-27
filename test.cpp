#include <bits/stdc++.h>

using namespace std;

void print_vector(vector<pair<int, int>> my_vec)
{
    for (auto i : my_vec)
    {
        cout << "| " << i.first << ' ' << i.second << ' ';
    }
    cout << "|\n";
}

int main()
{
    // string line1, line2, line3, tmp_str;
    // getline(cin, line1);
    // getline(cin, line2);
    // getline(cin, line3);

    string line1 = "5923", line2 = "56 27 73 34 99 45 32 17 64 57 18 11", line3 = "36 92 22 50 82", tmp_str;
    // expected: 16

    stringstream ss1(line1), ss2(line2), ss3(line3);
    string row_str;
    vector<pair<int, int>> hand, pile;
    while (ss1 >> tmp_str)
    {
        while (tmp_str.length() < 4)
        {
            tmp_str = '0' + tmp_str;
        }
        row_str = tmp_str;
    }
    vector<int> rows{stoi(row_str[0]), stoi(row_str[1]), stoi(row_str[2]), stoi(row_str[3])};
    while (ss2 >> tmp_str)
    {
        if (tmp_str.length() == 1)
            tmp_str = '0' + tmp_str;
        hand.push_back({stoi(tmp_str[0]), stoi(tmp_str[1])});
    }

    while (ss3 >> tmp_str)
    {
        if (tmp_str.length() == 1)
            tmp_str = '0' + tmp_str;
        pile.push_back({stoi(tmp_str[0]), stoi(tmp_str[1])});
    }

    for (auto i : hand)
    {
        for (auto &row : rows)
        {
            if (i.first == row)
            {
                row = i.second;
                if (i.first == i.second)
                {

                }
            }
            else if (i.second == row)
            {
                row = i.first;
                break;
            }
            else
            {
                hand.push_back(pile[0]);
                pile.erase(pile.begin());
            }
        }
    }
}
