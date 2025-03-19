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

int solve_superimposed(int N, int A, int B, vector<string> &s) {
    if (A == 0 && B == 0) {
        int count = 0;
        for (string i : s) {
            for (char j : i) {
                if (j != 'W') {
                    count++;
                }
            }
        }
        return count;
    }

    vector<vector<bool>> jump(N, vector<bool>(N));
    vector<vector<bool>> has_star(N, vector<bool>(N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int last_i = i - B;
            int last_j = j - A;
            int next_i = i + B;
            int next_j = j + A;

            if (s[i][j] == 'G') {
                if (last_i < 0 || last_j < 0) {
                    has_star[i][j] = 1;
                } else if (!jump[last_i][last_j]) {
                    has_star[i][j] = 1;
                }

                if (next_i < N && next_j < N) {
                    if (s[next_i][next_j] == 'B') {
                        has_star[i][j] = 1;
                    }
                }

                if (has_star[i][j]) {
                    if (next_i < N && next_j < N) {
                        if (s[next_i][next_j] != 'W') {
                            jump[i][j] = 1;
                        }
                    }
                }
            } else if (s[i][j] == 'B') {
                has_star[i][j] = 1;
                if (last_i < 0 || last_j < 0) {
                    return -1;
                }

                if (last_i >= 0 && last_j >= 0) {
                    if (s[last_i][last_j] == 'W') {
                        return -1;
                    }
                    if (!jump[last_i][last_j]) {
                        return -1;
                    }
                }
                if (next_i < N && next_j < N) {
                    if (s[next_i][next_j] != 'W') {
                        jump[i][j] = 1;
                    }
                }
            }
        }
    }

    int count = 0;
    for (auto i : has_star) {
        for (bool j : i) {
            if (j) count++;
        }
    }
    return count;
}

int main() {
    fio;

    int T;
    cin >> T;
    stringstream ans;
    while (T--) {
        int N, A, B;
        cin >> N >> A >> B;
        vector<string> s(N);
        for (int i = 0; i < N; i++) {
            cin >> s[i];
        }

        ans << solve_superimposed(N, A, B, s) << "\n";
    }
    cout << ans.str();
}
