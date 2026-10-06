#include <bits/stdc++.h>

using namespace std;

struct Point2i {
    long x, y;

    Point2i operator+(const Point2i& right) const {
        return {x + right.x, y + right.y};
    }

    Point2i operator-(const Point2i& right) const {
        return {x - right.x, y - right.y};
    }

    Point2i operator*(const long s) const {
        return {x * s, y * s};
    }

    double norm() const {
        return sqrt(x * x + y * y);
    }

    long norm_sq() const {
        return x * x + y * y;
    }

    long dot(const Point2i& right) const {
        return x * right.x + y * right.y;
    }

    long cross(const Point2i& right) const {
        return x * right.y - y * right.x;
    }

    bool operator<(const Point2i& right) const {
        return tie(x, y) < tie(right.x, right.y);
    }

    bool operator==(const Point2i& right) const {
        return x == right.x && y == right.y;
    }
};

vector<Point2i> convex_hull(vector<Point2i> pts, int n) {
    if (n <= 3) return pts;

    // Sorting by x then y
    sort(pts.begin(), pts.end());

    // Constructing the lower hull
    vector<Point2i> lower;
    for (auto p : pts) {
        while (lower.size() >= 2) {
            Point2i v = lower.back() - lower[lower.size() - 2];
            Point2i w = p - lower[lower.size() - 2];
            if (v.cross(w) > 0) break;
            lower.pop_back();
        }
        lower.push_back(p);
    }

    // Building the upper hull
    vector<Point2i> upper;
    reverse(pts.begin(), pts.end());
    for (auto p : pts) {
        while (upper.size() >= 2) {
            Point2i v = upper.back() - upper[upper.size() - 2];
            Point2i w = p - upper[upper.size() - 2];
            if (v.cross(w) > 0) break;
            upper.pop_back();
        }
        upper.push_back(p);
    }

    vector<Point2i> rtn;
    while (!lower.empty()) {
        rtn.push_back(lower.back());
        lower.pop_back();
    }
    if (rtn.back() == upper.back()) upper.pop_back();
    while (!upper.empty()) {
        rtn.push_back(upper.back());
        upper.pop_back();
    }
    if (rtn.front() == rtn.back() && rtn.size() > 1) rtn.pop_back();

    return rtn;
}

/**
 * Computes the area of a convex polygon
 */
double compute_area(vector<Point2i> pts, int n) {
    double rtn = 0;
    for (int i = 1; i < n - 1; i++) {
        Point2i v = pts[i + 1] - pts[0];
        Point2i w = pts[i] - pts[0];
        rtn += v.cross(w);
    }
    return rtn / 2.0;
}

int main() {
    int n;
    cin >> n;

    while (n > 0) {
        vector<Point2i> pts(n);
        for (auto& p : pts) cin >> p.x >> p.y;

        // Making the convex hull
        vector<Point2i> hull = convex_hull(pts, n);
        cout << compute_area(hull, hull.size()) << endl << flush;

        cin >> n;
    }
}