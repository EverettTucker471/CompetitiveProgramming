#include <bits/stdc++.h>

using namespace std;


struct Point2f {
    double x, y;

    Point2f operator-(const Point2f& right) const {
        return {x - right.x, y - right.y};
    }

    double norm() {
        return sqrt(x * x + y * y);
    }

    bool operator<(const Point2f& right) const {
        return tie(x, y) < tie(right.x, right.y);
    }

    bool operator==(const Point2f& right) const {
        return x == right.x && y == right.y;
    }
};

struct YSort {
    bool operator()(const Point2f& a, const Point2f& b) const {
        return tie(a.y, a.x) < tie(b.y, b.x);
    }
};


int main() {
    int n;
    cin >> n;

    while (n > 0) {
        vector<Point2f> pts(n);
        for (auto& p : pts) cin >> p.x >> p.y;

        int left = 0;
        pair<Point2f, Point2f> closest;
        double dist = DBL_MAX;
        sort(pts.begin(), pts.end());

        set<Point2f, YSort> y_set;
        
        for (int i = 0; i < n; i++) {
            while (pts[left].x < pts[i].x - dist) {
                y_set.erase(pts[left]);
                left++;
            }

            auto lower = y_set.lower_bound({DBL_MIN, pts[i].y - dist});
            auto upper = y_set.upper_bound({DBL_MAX, pts[i].y + dist});
            for (auto it = lower; it != upper; it++) {
                double d = (*it - pts[i]).norm();
                if (d < dist) {
                    dist = d;
                    closest.first = *it;
                    closest.second = pts[i];
                }
            }

            y_set.insert(pts[i]);
        }

        cout << setprecision(2) << fixed << closest.first.x << " " << closest.first.y << " " << closest.second.x << " " << closest.second.y << '\n';

        cin >> n;
    }
}