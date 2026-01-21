#include <bits/stdc++.h>

using namespace std;
#define all(a) a.begin(), a.end()
#define fio                  \
    ios::sync_with_stdio(0); \
    cin.tie(NULL)
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vll;

void solve() {
    int N;
    cin >> N;
    vi l(N);
    for (int i = 0; i < N; i++)
        cin >> l[i];

    int bid;
    for (int i = 0; i < N - 1; i++) {
        if (l[i] > l[i + 1]) {
            if (i == 0 || l[i - 1] <= l[i + 1]) {
                bid = i;
                break;
            }

            if (i + 1 == N - 1 or l[i] <= l[i + 2]) {
                bid = i + 1;
                break;
            }
        }
    }

    int bnum = l[bid];

    sort(all(l));
    int intid_min;
    for (int i = 0; i < N; i++) {
        if (l[i + 1] > bnum) {
            intid_min = i;
            break;
        }
    }
    int intid_max;
    for (int i = 0; i < N; i++) {
        if (l[i] == bnum) {
            intid_max = i;
            break;
        }
    }
    int intid;
    if (intid_min < bid) {
        intid = intid_min;
    } else {
        intid = intid_max;
    }

    unordered_set<int> ans;
    int lo = min(bid, intid), hi = max(bid, intid);
    if (bid > intid) {
        lo++;
        hi++;
    }

    for (int i = lo; i < hi; i++) {
        ans.insert(l[i]);
    }

    cout << ans.size() << '\n';
}

int main() {
    freopen("outofplace.in", "r", stdin);
    freopen("outofplace.out", "w", stdout);
    // fio;
    int T = 1;
    while (T--) {
        solve();
    }
}
