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

    Point2i operator*(long s) {
        return {x * s, y * s};
    }

    double norm() {
        return sqrt(x * x + y * y);
    }

    long norm_sq() {
        return x * x + y * y;
    }

    long dot(Point2i right) {
        return x * right.x + y * right.y;
    }

    long cross(Point2i right) {
        return x * right.y - y * right.x;
    }
};

int left(int i) {return (i + 1) % n;}
int right(int i) {return (n + i - 1) % n;}
int sign(int x) {
    if (x < 0) return -1;
    else if (x > 0) return 1;
    else return 0;
}

int main() {
    cin >> n >> k;
    vector<Point2i> pts(n);
    for (auto& x : pts) cin >> x.x >> x.y;
    for (int i = 0; i < n; i++) {
        pts.push_back(pts[i]);
    }

    // We solve this with rotating calipers
    long max_len = 0;
    
    int p1 = 0;  // Uniformly increasing pointer
    int p2 = 0;  // Dynamically increasing pointer
    vector<bool> vis(n, false);
    for (; p1 < n; p1++) {
        Point2i edge = pts[left(p1)] - pts[p1];

        while (p1 == p2 || left(p1) == p2 || sign(edge.cross(pts[left(p2)] - pts[p2])) == sign(edge.cross(pts[p2] - pts[right(p2)]))) {
            p2 = left(p2);
        }

        if (vis[p1]) continue;
        vis[p1] = true;

        // Now we have found two anti-podal pairs
        max_len = max(max_len, max((pts[p1] - pts[p2]).norm_sq(), (pts[left(p1)] - pts[p2]).norm_sq()));

        if (edge.cross(pts[left(p2)] - pts[p2]) == 0) {
            max_len = max(max_len, max((pts[p1] - pts[left(p2)]).norm_sq(), (pts[left(p1)] - pts[left(p2)]).norm_sq()));
            vis[p2] = true;
        }
    }

    // cout << sqrt(max_len) << '\n';
    cout << ceil((double) k / (2.0 * sqrt(max_len))) << '\n';
}