// https://cses.fi/problemset/task/1621
// #distinct value
// lesson:

#include "bits/stdc++.h"

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> arr;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        arr.push_back(x);
    }
    sort(arr.begin(), arr.end());
    int count = 1;
    for (int i = 1; i < n; i++) {
        if (arr[i - 1] != arr[i]) count++;
    }
    cout << count << endl;
}
