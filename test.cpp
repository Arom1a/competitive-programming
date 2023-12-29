#include <bits/stdc++.h>

using namespace std;

void print_vector(const vector<pair<int, int>> &my_vec)
{
    for (auto i : my_vec)
    {
        cout << "| " << i.first << ' ' << i.second << ' ';
    }
    cout << "|\n";
}

int summation(const vector<pair<int, int>> &my_vec)
{
    if (my_vec.size() != 0)
    {
        int sum = 0;
        for (auto i : my_vec)
        {
            sum += (i.first + i.second);
        }

        return sum;
    }
    else
    {
        return 0;
    }
}

int deal_with_double(int row_end, vector<pair<int, int>> &hand, vector<pair<int, int>> &pile)
{
    bool condition = true;
    while (condition)
    {
        for (int i = 0; i < hand.size(); i++)
        {
            if (hand[i].first == row_end)
            {
                row_end = hand[i].second;
                hand.erase(hand.begin() + i);
                condition = false;
                break;
            }
            else if (hand[i].second == row_end)
            {
                row_end = hand[i].first;
                hand.erase(hand.begin() + i);
                condition = false;
                break;
            }
        }

        if (condition && pile.size() != 0)
        {
            hand.push_back(pile.front());
            pile.erase(pile.begin());
            // print_vector(hand); // debug
        }
        if (pile.size() == 0)
        {
            condition = false;
        }
    }

    return row_end;
}

int main()
{
    string line1, line2, line3, tmp_str;
    getline(cin, line1);
    getline(cin, line2);
    getline(cin, line3);

    // string line1 = "5923",
    //        line2 = "56 27 73 34 99 45 32 17 64 57 18 11",
    //        line3 = "36 92 22 50 82",
    //        tmp_str;
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
    pile.push_back({0, 0});

    ////////////////////
    // initialization //
    ////////////////////

    int row_number = 0;
outer:
    cout << boolalpha; // debug
    while (pile.size() != 0 && hand.size() != 0)
    {
        // print_vector(hand); // debug
        // cout << (hand.size()) << '\n'; // debug
        // cout << "row2: " << rows_end[1] << '\n'; // debug
        // cout << "            row1: " << rows_end[0] << '\n';    // debug
        // cout << "            row2: " << rows_end[1] << '\n';    // debug
        // cout << "            row3: " << rows_end[2] << '\n';    // debug
        // cout << "            row4: " << rows_end[3] << '\n';    // debug
        for (int i = 0; i < hand.size(); i++)
        {
            // cout << "i = " << i << '\n'; // debug
            for (int j = 0; j < rows_end.size(); j++)
            {
                // cout << "j = " << j << '\n'; // debug
                // cout << row_number << '\n'; // debug
                // cout << "    hand.first = " << hand[i].second << " row_end = " << rows_end[row_number] << '\n'; // debug
                // cout << (hand[i].first == rows_end[row_number]) << '\n'; // debug
                if (hand[i].first == rows_end[row_number])
                {
                    rows_end[row_number] = hand[i].second;
                    // cout << i << '\n'; // debug
                    // cout << hand[i].first << ' ' << hand[i].second << '\n'; // debug
                    int first = hand[i].first, second = hand[i].second;
                    hand.erase(hand.begin() + i);
                    // cout << "executed\n"; // debug
                    if (first == second)
                    {
                        // cout << "executed deal with" << '\n'; // debug
                        rows_end[row_number] = deal_with_double(rows_end[row_number], hand, pile);
                    }
                    row_number = (row_number + 1) % rows_end.size();
                    // cout << "first" << '\n'; // debug
                    // cout << "goes to " << row_number << '\n'; // debug
                    goto outer;
                }
                else if (hand[i].second == rows_end[row_number])
                {
                    rows_end[row_number] = hand[i].first;
                    hand.erase(hand.begin() + i);
                    row_number = (row_number + 1) % rows_end.size();
                    // cout << "second" << '\n'; //debug
                    // cout << "goes to " << row_number << '\n'; // debug
                    goto outer;
                }
                row_number = (row_number + 1) % rows_end.size();
            }
        }

        hand.push_back(pile.front());
        pile.erase(pile.begin());
    }
    // print_vector(hand); // debug
    cout << summation(hand) << '\n';
}
