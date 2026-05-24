#include <stdio.h>
using namespace std;

bool f(int i) {
    return i < 79;
}

int binary_search() {
    /* We know that f() is a monotonic function, namely that
     if i < j then f(i) <= f(j)

     The goal is to find the smallest index i in the range [0,1000000]
     such that f(i) = 1.  If there is no index in that range with f(i)=1
     then return -1.
  */

    int lo, hi, m;

    lo = 0;
    hi = 100;

    /* Induction hypothesis at start of loop:
     lo < hi and f(lo) = 0, f(hi) = 1 */
    while (lo + 1 < hi) {
        m = lo + (hi - lo) / 2;
        if (f(m)) lo = m;
        else hi = m;
    }
    return hi;
}

int main() {
    printf("%d\n", binary_search());
    return 0;
}
