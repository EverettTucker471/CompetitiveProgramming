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

int point_in_polygon(vector<Point2i>& pts, Point2i test, int n) {
    
}

int main() {
    int n, m;
    Point2i test;
    cin >> n;

    while (n > 0) {
        vector<Point2i> p(n);
        for (auto& x : p) cin >> x.x >> x.y;

        cin >> m;
        while (m--) {
            cin >> test.x >> test.y;
            int res = point_in_polygon(p, test, n);
        }
    }
}