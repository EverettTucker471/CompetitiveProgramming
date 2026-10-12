#include <bits/stdc++.h>

using namespace std;

struct Point2f {
    double x, y;

    Point2f operator+(Point2f right) {
        return {x + right.x, y + right.y};
    }

    Point2f operator-(Point2f right) {
        return {x - right.x, y - right.y};
    }

    Point2f operator*(double s) {
        return {x * s, y * s};
    }

    double cross(Point2f right) {
        return x * right.y - y * right.x;
    }
};

int main() {
    int n, a;
    cin >> n;
    vector<Point2f> p(n);
    for (auto& x : p) cin >> x.x >> x.y;
    cin >> a;

    // Compute the area
    double area = 0;
    for (int i = 1; i < n; i++) {
        area += (p[(i + 1) % n] - p[0]).cross(p[i] - p[0]);
    }

    area = -area / 2.0;
    double scale = sqrt(a / area);
    for (auto& x : p) {
        x.x *= scale;
        x.y *= scale;
    }

    Point2f offset = {x: DBL_MAX, y: DBL_MAX};
    for (auto x : p) {
        offset.x = min(offset.x, x.x);
        offset.y = min(offset.y, x.y);
    }

    for (auto& x : p) {
        x = x - offset;
    }

    for (auto x : p) {
        cout << x.x << " " << x.y << '\n';
    }
}