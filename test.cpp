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

int deal_with_double(int row_end, vector<pair<int, int>> &hand)
{
loop:
    while (true)
    {
        for (auto i : hand)
        {
            if (i.first == row_end)
            {
                row_end = i.second;
                goto loop;
            }
            else if (i.second == row_end)
            {
                row_end = i.first;
                goto loop;
            }
        }

        break;
    }

    return row_end;
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

    vector<int> rows_end(4);
    for (int i = 0; i < 4; i++)
    {
        rows_end[i] = row_str[i] - '0';
    }

    while (ss2 >> tmp_str)
    {
        if (tmp_str.length() == 1)
            tmp_str = '0' + tmp_str;
        hand.push_back({tmp_str[0] - '0', tmp_str[1] - '0'});
    }
    while (ss3 >> tmp_str)
    {
        if (tmp_str.length() == 1)
            tmp_str = '0' + tmp_str;
        pile.push_back({tmp_str[0] - '0', tmp_str[1] - '0'});
    }

    // initialization

    int row_number = 0;
    while (pile.size() != 0)
    {
        for (int i = 0; i < hand.size(); i++)
        {
            cout << "i = " << i << '\n';
            for (int j = 0; j < rows_end.size(); j++, row_number = (row_number+1) % rows_end.size())
            {
                cout << "    j = " << j << '\n';
                if (hand[i].first == rows_end[row_number])
                {
                    rows_end[row_number] = hand[i].second;
                    hand.erase(hand.begin() + i);
                    if (hand[i].first == hand[i].second)
                    {
                        rows_end[row_number] = deal_with_double(rows_end[row_number], hand);
                        cout << "executed deal with" << '\n';
                        break;
                    }
                    break;
                }
                else if (hand[i].second == rows_end[row_number])
                {
                    rows_end[row_number] = hand[i].first;
                    hand.erase(hand.begin() + i);
                    break;
                }
                else
                {
                    cout << "executed1" << '\n';
                    hand.push_back(pile.front());
                    cout << "executed2" << '\n';
                    print_vector(pile);
                    cout << pile.size() << '\n';
                    pile.erase(pile.begin());
                    cout << "executed3" << '\n';
                    row_number--;
                }
            }
        }
    }
}
