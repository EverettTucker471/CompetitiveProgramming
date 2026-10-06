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
};

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

struct Point3f {
    double x, y, z;

    Point3f operator+(Point3f right) {
        return {
            x: x + right.x,
            y: y + right.y,
            z: z + right.z,
        };
    }

    Point3f operator-(Point3f right) {
        return {
            x: x - right.x, 
            y: y - right.y,
            z: z - right.z,
        };
    }

    Point3f operator*(double s) {
        return {x * s, y * s, y * s};
    }

    double norm() {
        return sqrt(x * x + y * y + z * z);
    }

    double norm_sq() {
        return x * x + y * y + z * z;
    }

    double dot(Point3f right) {
        return x * right.x + y * right.y + z * right.z;
    }

    Point3f cross(Point3f right) {
        return {
            x: y * right.z - z * right.y,
            y: z * right.x - x * right.z,
            z: x * right.y - y * right.x,
        };
    }
};