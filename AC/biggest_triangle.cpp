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

    Point2f perp() {
        return {-y, x};
    }

    double dot(Point2f right) {
        return x * right.x + y * right.y;
    }

    double cross(Point2f right) {
        return x * right.y - y * right.x;
    }
};

int n;
vector<pair<Point2f, Point2f>> lines;

/**
 * Gets the unique intersection point between two lines,
 * if it exists
 */
optional<Point2f> get_intersection(int i, int j) {
    Point2f a = lines[i].first;
    Point2f b = lines[i].second;
    Point2f c = lines[j].first;
    Point2f d = lines[j].second;

    double orient = (d - c).cross(a - b);
    double t = (d - c).cross(a - c) / orient;

    if (orient == 0) {
        return nullopt;
    } else {
        return {a + (b - a) * t};    
    }
}

double compute_perimeter(int i, int j, int k) {
    Point2f a, b, c;
    if (get_intersection(i, j)) a = get_intersection(i, j).value(); else return -1; 
    if (get_intersection(j, k)) b = get_intersection(j, k).value(); else return -1; 
    if (get_intersection(k, i)) c = get_intersection(k, i).value(); else return -1;
    return (a - b).norm() + (b - c).norm() + (a - c).norm();
}

int main() {
    cin >> n;

    lines.assign(n, {});
    for (auto& l : lines) {
        cin >> l.first.x >> l.first.y >> l.second.x >> l.second.y;
    }

    double res = -1;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                res = max(res, compute_perimeter(i, j, k));
            }
        }
    }

    if (res <= 0.0) {
        cout << "no triangle\n";
    } else {
        printf("%.6lf\n", res);
    }
}