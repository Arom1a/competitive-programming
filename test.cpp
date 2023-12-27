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
        for (int i = 0; i < hand.size(); i++)
        {
            if (hand[i].first == row_end)
            {
                row_end = hand[i].second;
                hand.erase(hand.begin() + i);
                goto loop;
            }
            else if (hand[i].second == row_end)
            {
                row_end = hand[i].first;
                hand.erase(hand.begin() + i);
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

    ////////////////////
    // initialization //
    ////////////////////

    int row_number = 0;
outer:
    while (pile.size() != 0)
    {
        for (int i = 0; i < hand.size(); i++)
        {
            cout << "i = " << i << '\n'; // debug
            for (int j = 0; j < rows_end.size(); j++)
            {
                cout << "    hand = " << hand[i].first << " row_num = " << rows_end[row_number] << '\n'; // debug
                if (hand[i].first == rows_end[row_number])
                {
                    rows_end[row_number] = hand[i].second;
                    hand.erase(hand.begin() + i);
                    cout << "executed\n"; // debug
                    if (hand[i].first == hand[i].second)
                    {
                        rows_end[row_number] = deal_with_double(rows_end[row_number], hand);
                        cout << "executed deal with" << '\n'; // debug
                    }
                    row_number = (row_number + 1) % rows_end.size();
                    goto outer;
                }
                else if (hand[i].second == rows_end[row_number])
                {
                    rows_end[row_number] = hand[i].first;
                    hand.erase(hand.begin() + i);
                    row_number = (row_number + 1) % rows_end.size();
                    goto outer;
                }
            }
        }

        hand.push_back(pile.front());
        pile.erase(pile.begin()); // This one
        row_number--;
    }
    print_vector(hand);
}
