#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <numeric>
#include <limits>
#include <utility>

using namespace std;

void print_vector(vector<long> my_vec)
{
    for (auto i : my_vec)
    {
        cout << i << ' ';
    }
    cout << '\n';
}

int main()
{
    int N, M;
    cin >> N >> M;
    vector<long> h_cow(N);   // height_of_cow
    vector<long> h_candy(M); // height_of_candy
    for (long &i : h_cow)
        cin >> i;
    for (long &i : h_candy)
        cin >> i;

    // int N = 3, M = 2;
    // vector<long> h_cow{3, 2, 5};
    // vector<long> h_candy{6, 1};
    // Expect: 7 2 7

    for (long i : h_candy)
    {
        pair<long, long> candy{0, i};
        for (long &j : h_cow)
        {
            if (candy.first == candy.second)
                break;
            if (candy.first < j & j < i)
            {
                long eat = j - candy.first;
                candy.first = j;
                j += eat;
            }
            else if (j > candy.second)
            {
                long eat = candy.second - candy.first;
                j += eat;
                candy.first = 0;
                candy.second = 0;
            }
        }
    }
    for (long i : h_cow)
    {
        cout << i << '\n';
    }
}