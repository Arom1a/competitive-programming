#include "bits/stdc++.h"

typedef long long ll;
using namespace std;

template <typename T>
void print_vector(const vector<T> &my_vec) {
    for (const T &i : my_vec)
        cout << i << ' ';
    cout << endl;
}

vector<string> gene_code(int n) {
    if (n == 1)
        return vector<string>{"0", "1"};
    vector<string> past = gene_code(n - 1), current(pow(2, n));
    ll half = pow(2, n - 1);
    for (int i = 0; i < half; i++)
        current[i] = '0' + past[i];
    reverse(past.begin(), past.end());
    for (int i = 0; i < half; i++)
        current[half + i] = '1' + past[i];

    return current;
}

int main() {
    int n;
    cin >> n;
    vector<string> ans = gene_code(n);
    for (auto i : ans)
        cout << i << '\n';
}
