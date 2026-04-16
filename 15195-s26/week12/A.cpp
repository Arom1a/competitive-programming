#include <bits/stdc++.h>

using namespace std;
#define all(a) a.begin(), a.end()
template <typename T>
using vec = vector<T>;
using ll = long long;
using vi = vec<int>;
using vvi = vec<vi>;
using vll = vec<ll>;
using vvll = vec<vll>;
using vb = vec<bool>;
using vvb = vec<vb>;
using vs = vec<string>;
using vvs = vec<vs>;
template <typename T>
using max_heap = priority_queue<T>;
template <typename T>
using min_heap = priority_queue<T, vector<T>, greater<T>>;

int get_smallest_two_if_more_than_two_factors(long long n, long long* p1, long long* p2) {
    unsigned long long un = n < 0 ? -(unsigned long long)n : (unsigned long long)n;

    if (un <= 1) return 2;

    int count = 0;
    long long factors[2] = {0, 0};

    while (un % 2 == 0) {
        if (count < 2) {
            factors[count] = 2;
        }
        count++;
        un /= 2;

        if (count > 2) {
            *p1 = factors[0];
            *p2 = factors[1];
            return 0;
        }
    }

    for (unsigned long long i = 3; i * i <= un; i += 2) {
        while (un % i == 0) {
            if (count < 2) {
                factors[count] = i;
            }
            count++;
            un /= i;

            if (count > 2) {
                *p1 = factors[0];
                *p2 = factors[1];
                return 0;
            }
        }
    }

    if (un > 1) {
        count++;
    }

    if (count > 2) {
        *p1 = factors[0];
        *p2 = factors[1];
        return 0;
    }

    if (count == 1) {
        return 2;
    }

    return 1;
}

void solve() {
    ll q;
    cin >> q;

    ll n1, n2;
    int ret = get_smallest_two_if_more_than_two_factors(q, &n1, &n2);
    if (ret == 0) {
        cout << 1 << '\n';
        cout << n1 * n2 << '\n';
    } else if (ret == 1) {
        cout << 2 << '\n';
    } else {
        cout << 1 << '\n';
        cout << 0 << '\n';
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int T = 1;
    while (T--) {
        solve();
    }
}
