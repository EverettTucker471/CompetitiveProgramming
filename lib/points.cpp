#include <vector>
#include <iostream>
#include <unordered_map>
#include <map>
#include <unordered_set>
#include <set>
#include <cmath>
#include <algorithm>
#include <climits>
#include <numeric>

using namespace std;

struct Point {
    double x, y;
    bool operator == (Point const& o) const {
        return x == o.x && y == o.y;
    }
};

/**
 * Returns the orientation of three points in space
 * -1 for clockwise
 * 1 for counter-clockwise
 * 0 for colinear
 */
int orientation(Point a, Point b, Point c) {
    double v = a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y);
    if (v < 0) return -1; // clockwise
    if (v > 0) return 1; // counter-clockwise
    return 0;
}

/**
 * Determines if a point is part of the convex hull
 * Allows including collinear point in the hull, or not
 */
bool cw(Point a, Point b, Point c, bool include_collinear) {
    int o = orientation(a, b, c);
    return o < 0 || (include_collinear && o == 0);
}

/**
 * Determines whether three points are collinear
 */
bool collinear(Point a, Point b, Point c) {
    return orientation(a, b, c) == 0;
}

/**
 * Returns the convex hull as a vector of Points by reference
 */
void convex_hull(vector<Point>& a, bool include_collinear) {
    // Finding the smallest point by x value, ties broken by y value
    Point p0 = *min_element(a.begin(), a.end(), [](Point a, Point b) {
        return make_pair(a.y, a.x) < make_pair(b.y, b.x);
    });

    // Sorting the points clockwise by polar angle
    sort(a.begin(), a.end(), [&p0](const Point& a, const Point& b) {
        int o = orientation(p0, a, b);
        if (o == 0) {
            return (p0.x - a.x) * (p0.x - a.x) + (p0.y - a.y) * (p0.y - a.y)
                < (p0.x - b.x) * (p0.x - b.x) + (p0.y - b.y) * (p0.y - b.y);
        }
        return o < 0;
    });

    // If we need collinear, get the largest points by polar angle
    // Then reverse their order in the result vector
    if (include_collinear) {
        int i = (int) a.size() - 1;
        while (i >= 0 && collinear(p0, a[i], a.back())) i--;
        reverse(a.begin() + i + 1, a.end());
    }

    // Pushing point in the convex hull onto the stack
    vector<Point> stack;
    for (int i = 0; i < a.size(); i++) {
        while (stack.size() > 1 && !cw(stack[stack.size() - 2], stack.back(), a[i], include_collinear)) {
            stack.pop_back();
        }
        stack.push_back(a[i]);
    }

    // Removing collinear points
    if (include_collinear == false && stack.size() == 2 && stack[0] == stack[1]) {
        stack.pop_back();
    }

    a = stack;  // Setting the stack as our output
}

/**
 * Computes the area of a simple polygon with the given points
 */
double area(const vector<Point>& points) {
    double rtn = 0;
    for (int i = 0; i < points.size(); i++) {
        Point p = i ? points[i - 1] : points.back();
        Point q = points[i];
        rtn += (p.x - q.x) * (p.y + q.y);
    }

    return abs(rtn) / 2;
}

