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

struct pt {
    ll x;
    ll y;
};

pt lim = {(ll)1e9 + 1, 1};

bool on_segment(pt p, pt q, pt r) {
    if (r.x <= max(p.x, q.x) && r.x >= min(p.x, q.x) && r.y <= max(p.y, q.y) &&
        r.y >= min(p.y, q.y)) {
        return true;
    }
    return false;
}

ll orientation(pt p, pt q, pt r) {
    ll val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);

    if (val == 0) return 0;
    return (val > 0) ? 1 : 2;
}

bool do_intersect(pt p1, pt q1, pt p2, pt q2) {
    ll o1 = orientation(p1, q1, p2);
    ll o2 = orientation(p1, q1, q2);
    ll o3 = orientation(p2, q2, p1);
    ll o4 = orientation(p2, q2, q1);

    if (o1 != o2 && o3 != o4) return true;

    if (o1 == 0 && on_segment(p1, q1, p2)) return true;
    if (o2 == 0 && on_segment(p1, q1, q2)) return true;
    if (o3 == 0 && on_segment(p2, q2, p1)) return true;
    if (o4 == 0 && on_segment(p2, q2, q1)) return true;

    return false;
}

bool is_pt_on_segment(pt A, pt B, pt C) {
    ll crossProduct = (B.x - A.x) * (C.y - A.y) - (B.y - A.y) * (C.x - A.x);

    if (crossProduct != 0) {
        return false;
    }

    if (C.x >= min(A.x, B.x) && C.x <= max(A.x, B.x) && C.y >= min(A.y, B.y) &&
        C.y <= max(A.y, B.y)) {
        return true;
    }

    return false;
}

bool check_boundary(vec<pt>& pts, pt p) {
    ll n = pts.size();
    for (int i = 0; i < n - 1; i++) {
        if (is_pt_on_segment(pts[i], pts[i + 1], p)) return true;
    }
    if (is_pt_on_segment(pts[n - 1], pts[0], p)) return true;

    return false;
}

bool check_inside(vec<pt>& pts, pt p) {
    ll cnt = 0;
    ll n = pts.size();
    for (int i = 0; i < n - 1; i++) {
        if (do_intersect(pts[i], pts[i + 1], p, lim)) {
            cnt += 1;
        }
    }
    if (do_intersect(pts[n - 1], pts[0], p, lim)) cnt += 1;

    if (cnt % 2 == 1) return true;
    else return false;
}

void solve(vec<pt>& pts) {
    ll x, y;
    cin >> x >> y;
    pt p = {x, y};
    lim.y = y + 1;
    if (check_boundary(pts, p)) {
        cout << "BOUNDARY\n";
    } else if (check_inside(pts, p)) {
        cout << "INSIDE\n";
    } else {
        cout << "OUTSIDE\n";
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int n, m;
    cin >> n >> m;
    vec<pt> pts(n);
    for (int i = 0; i < n; i++) {
        ll x, y;
        cin >> x >> y;
        pts[i] = {x, y};
    }
    while (m--) {
        solve(pts);
    }
}
