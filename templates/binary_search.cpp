#include <bits/stdc++.h>
using namespace std;

// non-decreasing
bool nondec(int i) {
    return i >= 34785;
}

// non-increasing
bool noninc(int i) {
    return i <= 34785;
}

// ok is a number that makes test(ok) == true
// ng is a number that makes test(ng) == false
int bs(int ok, int ng, bool (*test)(int)) {
    int m;

    while (abs(ok - ng) > 1) {
        // change when overflow may occur!
        m = (ok + ng) / 2;
        if (test(m)) ok = m;
        else ng = m;
    }

    return ok;
}

int main() {
    cout << bs(1000000, 0, nondec) << '\n';
    cout << bs(0, 1000000, noninc) << '\n';
}
