#include "bits/stdc++.h"

using namespace std;
#define all(a) a.begin(), a.end()
#define fio                  \
    ios::sync_with_stdio(0); \
    cin.tie(NULL)
#define f first
#define s second
#define mp make_pair
typedef long long ll;
typedef vector<int> vi;

template <typename T>
void print_1dvec(const vector<T> &vec) {
    for (const T &i : vec)
        cout << i << ' ';
    cout << '\n';
}

template <typename T>
void print_2dvec(const vector<vector<T>> &vec) {
    for (const vector<T> &i : vec) {
        for (const T &j : i) {
            cout << j << ' ';
        }
        cout << '\n';
    }
}

stringstream cow_checkups(int N, vector<int> &a, vector<int> &b) {
    vector<int> ans(N + 1);
    // for (int i = 0; i < N; i++) {
    //     for (int j = i; j < N; j++) {
    //         vector<int> a_copy(all(a));
    //         // cout << "swapping: " << i << ' ' << j << '\n';
    //         // print_1dvec(a_copy);
    //         for (int k = 0; k < (j - i + 1) / 2; k++) {
    //             swap(a_copy[i + k], a_copy[j - k]);
    //         }
    //         // print_1dvec(a_copy);
    //         // cout << '\n';
    //
    //         int count = 0;
    //         for (int k = 0; k < N; k++) {
    //             if (a_copy[k] == b[k]) {
    //                 count++;
    //             }
    //         }
    //         ans[count]++;
    //     }
    // }

    int base_count = 0;
    for (int i = 0; i < N; i++) {
        if (a[i] == b[i]) {
            base_count++;
        }
    }
    ans[base_count] += N;

    for (int i = 0; i < N; i++) {
        int l = i - 1;
        int r = i + 1;
        int count = base_count;
        while (l >= 0 && r < N) {
            if (a[l] == b[l]) count--;
            if (a[r] == b[r]) count--;
            if (a[l] == b[r]) count++;
            if (a[r] == b[l]) count++;

            ans[count]++;
            l--;
            r++;
        }
    }

    for (int i = 0; i < N - 1; i++) {
        int l = i;
        int r = i + 1;
        int count = base_count;
        while (l >= 0 && r < N) {
            if (a[l] == b[l]) count--;
            if (a[r] == b[r]) count--;
            if (a[l] == b[r]) count++;
            if (a[r] == b[l]) count++;

            ans[count]++;
            l--;
            r++;
        }
    }

    stringstream ss;
    for (int i : ans) {
        ss << i << '\n';
    }
    return ss;
}

int main() {
    fio;

    int N;
    cin >> N;
    vector<int> a(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    vector<int> b(N);
    for (int i = 0; i < N; i++) {
        cin >> b[i];
    }

    cout << cow_checkups(N, a, b).str();
}
