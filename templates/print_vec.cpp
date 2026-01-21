#include <bits/stdc++.h>
using namespace std;

template <typename T>
void print_1dvec(const vector<T>& vec) {
    for (const T& i : vec)
        cout << i << ' ';
    cout << '\n';
}

template <typename T>
void print_2dvec(const vector<vector<T>>& vec) {
    for (const vector<T>& i : vec) {
        for (const T& j : i) {
            cout << j << ' ';
        }
        cout << '\n';
    }
}
