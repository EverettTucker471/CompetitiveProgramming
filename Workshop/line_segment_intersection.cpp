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

    double norm() {
        return sqrt(x * x + y * y);
    }

    double norm_sq() {
        return x * x + y * y;
    }

    double dot(Point2f right) {
        return x * right.x + y * right.y;
    }

    double cross(Point2f right) {
        return x * right.y - y * right.x;
    }

    bool operator<(const Point2f& right) const {
        return tie(x, y) < tie(right.x, right.y);
    }

    bool operator==(const Point2f& right) const {
        return x == right.x && y == right.y;
    }
};


vector<Point2f> intersection(Point2f a, Point2f b, Point2f c, Point2f d) {
    // Checking orientation
    double orient = (d - c).cross(a - b);

    if (orient == 0.0) {
        // The lines are parallel

        // Finding if the lines are collinear (stronger)
        if ((c - b).cross(b - a) == 0) {
            // Sorting the points
            Point2f p1 = min(a, b);
            Point2f p2 = max(a, b);
            Point2f p3 = min(c, d);
            Point2f p4 = max(c, d);

            if (p3 < p1) {
                pair<Point2f, Point2f> temp = {p1, p2};
                p1 = p3;
                p2 = p4;
                p3 = temp.first;
                p4 = temp.second;
            }

            if (p2 < p3) {
                return {};
            } else if (p2 == p3) {
                return {p2};  // Single Point intersection
            } else {
                Point2f endpoint = p2 < p4 ? p2 : p4;
                if (endpoint == p3) return {p3};
                else return {p3, endpoint};
            }
        } else {
            return {};  // Parallel but not collinear
        }
    } else {
        // Lines are not colinear
        double t = (d - c).cross(a - c) / orient;
        double u = (b - a).cross(a - c) / orient;

        // Either unique or no intersection
        if (t >= 0 && t <= 1 && u >= 0 && u <= 1) {
            return {a + (b - a) * t};  // Single intersection
            // return {c + (d - c) * u};  // Should be the same
        } else {
            return {};  // No intersection
        }
    }
}

int main() {
    int _;
    cin >> _;
    Point2f a, b, c, d;

    while (_--) {
        cin >> a.x >> a.y;
        cin >> b.x >> b.y;
        cin >> c.x >> c.y;
        cin >> d.x >> d.y;
    
        // Line segment from a -> b and x -> y
        vector<Point2f> res = intersection(a, b, c, d);
        if (res.empty()) {
            cout << "none\n";
        } else {
            for (auto& x : res) {
                if (abs(x.x) < 0.005) x.x = 0;
                if (abs(x.y) < 0.005) x.y = 0;
                printf("%.2lf %.2lf ", x.x, x.y);
            }
            cout << '\n';
        }
    }
}