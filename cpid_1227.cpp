// ugly code, bruh

#include "bits/stdc++.h"

typedef long long ll;
using namespace std;

template <typename T>
void print_vector(const vector<T> &my_vec) {
    for (const T &i : my_vec)
        cout << i << ' ';
    cout << endl;
}

int main() {
    // input
    int N;
    cin >> N;
    string str;
    cin >> str;
    if (N % 2 == 1)
        str += str.back();
    vector<int> num((N + 1) / 2);
    for (int i = 0; i < (N + 1) / 2; i++) {
        if (str.substr(2 * i, 2) == "GH")
            num[i] = -1;
        if (str.substr(2 * i, 2) == "HG")
            num[i] = 1;
    }

    vector<int> new_tmp_num;
    new_tmp_num.push_back(num.front());
    for (int i = 1; i < num.size(); i++) {
        if (new_tmp_num.back() == num[i])
            continue;
        new_tmp_num.push_back(num[i]);
    }
    vector<int> new_num;
    for (int i : new_tmp_num) {
        if (i != 0)
            new_num.push_back(i);
    }
    vector<int> new_new_num;
    int minus_one_num = -1;
    new_new_num.push_back(new_num.front());
    for (int i = 1; i < new_num.size(); i++) {
        if (new_new_num.back() == new_num[i])
            continue;
        new_new_num.push_back(new_num[i]);
    }

    for (int i : new_new_num) {
        if (i == -1)
            minus_one_num++;
    }
    // print_vector(new_new_num);  // debug

    int ans = 0;
    ans += (1 + (new_new_num.front() != -1));
    ans += minus_one_num * 2;

    cout << ans << '\n';
}
