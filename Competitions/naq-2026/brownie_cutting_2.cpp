#include <bits/stdc++.h>

using namespace std;

int n, k;

struct Point2i {
    long x, y;

    Point2i operator+(Point2i right) {
        return {x + right.x, y + right.y};
    }

    Point2i operator-(Point2i right) {
        return {x - right.x, y - right.y};
    }

    long norm_sq() {
        return x * x + y * y;
    }
};

long area(Point2i p, Point2i q, Point2i r) {
    return abs((p.x * q.y + q.x * r.y + r.x * p.y) - 
               (p.y * q.x + q.y * r.x + r.y * p.x));
}

int main() {
    cin >> n >> k;
    vector<Point2i> pts(n);
    for (auto& x : pts) cin >> x.x >> x.y;
    for (int i = 0; i < n; i++) {
        pts.push_back(pts[i]);
    }

    int j = 1;
    while (area(pts[n - 1], pts[0], pts[(j + 1) % n]) > area(pts[n - 1], pts[0], pts[j])) {
        j++;
    }

    long max_len = 0;
    for (int i = 0; i < n; i++) {
        while (area(pts[i], pts[(i + 1) % n], pts[(j + 1) % n]) > area(pts[i], pts[(i + 1) % n], pts[j])) {
            max_len = max(max_len, (pts[i] - pts[(j + 1) % n]).norm_sq());
            j = (j + 1) % n;
        }
        max_len = max(max_len, (pts[i] - pts[j]).norm_sq());
    }

    // cout << max_len << '\n';
    cout << ceil((double) k / (2.0 * sqrt(max_len))) << '\n';
}