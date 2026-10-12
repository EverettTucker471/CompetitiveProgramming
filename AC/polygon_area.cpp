#include <bits/stdc++.h>

using namespace std;

struct Point2i {
    long x, y;

    Point2i operator-(const Point2i& right) const {
        return {x - right.x, y - right.y};
    }

    long cross(const Point2i& right) const {
        return x * right.y - y * right.x;
    }
};


int main() {
    // Works for all polygons, not just convex ones
    int n;
    cin >> n;

    while (n > 0) {
        vector<Point2i> p(n);
        for (auto& x : p) cin >> x.x >> x.y;

        long res = 0;
        for (int i = 1; i < n; i++) {
            res += (p[(i + 1) % n] - p[0]).cross(p[i] - p[0]);
        }

        if (res < 0) {
            // Counter-clockwise ordering
            printf("CCW %.1lf\n", -res / 2.0);
        } else {
            // Clockwise ordering
            printf("CW %.1lf\n", res / 2.0);
        }

        cin >> n;
    }
}