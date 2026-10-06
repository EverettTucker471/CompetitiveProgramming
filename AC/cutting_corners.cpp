#include <bits/stdc++.h>

using namespace std;

struct Point2i {
    long x, y;

    Point2i operator-(Point2i right) {
        return {x - right.x, y - right.y};
    }

    double norm() {
        return sqrt(x * x + y * y);
    }

    long dot(Point2i right) {
        return x * right.x + y * right.y;
    }
};

double compute_angle(vector<Point2i>& p, int i, int j, int k) {
    Point2i v = p[i] - p[j];
    Point2i w = p[k] - p[j];
    return acos(v.dot(w) / (v.norm() * w.norm()));
}

pair<int, double> compute_min_angle(vector<Point2i>& p, int n) {
    int idx = 0;
    double rtn = 2 * M_PI;
    for (int i = 0; i < n; i++) {
        double angle = compute_angle(p, (i - 1 + n) % n, i, (i + 1) % n);
        if (angle < rtn) {
            idx = i;
            rtn = angle;
        }
    }

    return {idx, rtn};
}

int main() {
    int n;
    cin >> n;

    while (n > 0) {
        vector<Point2i> pts(n);
        for (auto& p : pts) cin >> p.x >> p.y;
        reverse(pts.begin(), pts.end());  // Converting from clockwise to counter-clockwise

        while (n > 3) {
            pair<int, double> res = compute_min_angle(pts, n);

            // Checking if this would make a smaller angle
            double a = compute_angle(pts, (res.first - 1 + n) % n, (res.first + 1) % n, (res.first + 2) % n);
            double b = compute_angle(pts, (res.first - 2 + n) % n, (res.first - 1 + n) % n, (res.first + 1) % n);
            if (a < res.second || b < res.second) break;

            // Remove the i-th index and decrement n
            pts.erase(pts.begin() + res.first);
            n--;
        }

        // Printing everything in pts now
        reverse(pts.begin(), pts.end());
        cout << n;
        for (auto x : pts) cout << " " << x.x << " " << x.y; 
        cout << endl << flush;

        cin >> n;
    }
}