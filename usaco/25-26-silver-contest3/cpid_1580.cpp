// incomplete

#include <bits/stdc++.h>

using namespace std;
#define all(a) a.begin(), a.end()
#define fio                  \
    ios::sync_with_stdio(0); \
    cin.tie(NULL)
template <typename T>
using vec = vector<T>;
typedef long long ll;
typedef vec<int> vi;
typedef vec<vec<int>> vvi;
typedef vec<ll> vll;
typedef vec<vec<ll>> vvll;
typedef vec<bool> vb;
typedef vec<vec<bool>> vvb;
typedef vec<string> vs;
typedef vec<vec<string>> vvs;

int N;
vll a;
vll sgt;
int sgt_size;

ll mul(ll x, ll y) {
    if (x == 1) return y;
    if (y == 1) return x;
    if (LONG_LONG_MAX / x < y) return LONG_LONG_MAX;
    return x * y;
}

void update(int idx, ll val) {
    idx += sgt_size;
    sgt[idx] = val;
    idx /= 2;
    while (idx > 0) {
        sgt[idx] = mul(sgt[2 * idx], sgt[2 * idx + 1]);
        idx /= 2;
    }
}

int main() {
    fio;
    if (!(cin >> N)) return 0;

    a.resize(N + 1);
    for (int i = 1; i <= N; ++i) {
        cin >> a[i];
    }

    sgt_size = 1;
    while (sgt_size <= N + 1)
        sgt_size *= 2;

    sgt.assign(2 * sgt_size, 1);

    for (int i = 1; i <= N; ++i) {
        if (i == 1) {
            sgt[sgt_size + i] = a[1] + 1;
        } else {
            sgt[sgt_size + i] = (a[i] + a[i - 1] - 1) / a[i - 1];
        }
    }

    for (int i = sgt_size - 1; i > 0; --i) {
        sgt[i] = mul(sgt[2 * i], sgt[2 * i + 1]);
    }

    int Q;
    cin >> Q;
    while (Q--) {
        int i;
        ll v, t;
        cin >> i >> v >> t;

        a[i] = v;

        if (i == 1) {
            update(1, a[1] + 1);
            if (N >= 2) {
                update(2, (a[2] + a[1] - 1) / a[1]);
            }
        } else {
            update(i, (a[i] + a[i - 1] - 1) / a[i - 1]);
            if (i + 1 <= N) {
                update(i + 1, (a[i + 1] + a[i] - 1) / a[i]);
            }
        }

        ll TN = sgt[1];
        ll ans = 0;

        if (t >= N - 1) {
            ll num_flips = (t - N + 1) / TN;
            ans = num_flips * a[N];
        }

        cout << ans << '\n';
    }
}
