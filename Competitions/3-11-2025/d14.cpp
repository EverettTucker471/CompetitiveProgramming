#include<vector>
#include<iostream>
#include<unordered_map>
#include<map>
#include<unordered_set>
#include<set>
#include<cmath>
#include<climits>
#include <algorithm>

using namespace std;

bool comp(pair<int, int> a, pair<int, int> b) {
    // Sorting by rightmost point, then radius
    if (a.first - a.second == b.first - b.second) {
        return a.second > b.second;
    }
    return a.first - a.second < b.first - b.second;
}

/**
 * Computes the number of integer points inside a circle
 * @param r the radius of the circle
 * @return the number of integer points inside a circle of radius r
 */
long complete(int r) {
    cout << "Complete: " << r << endl;
    long rtn = 0;
    for (int i = 0; i <= r; i++) {
        rtn += (int) sqrt(r * r - i * i);
    }
    return 4 * rtn + 1;
}

/**
 * Computes the number of points inside the intersection of two circles
 * Assumes the circles are on the same x or y level
 * @param r1 the radius of the first circle
 * @param r2 the radius of the second circle
 * @param d the distance between the circles
 * @return the number of integer points inside both circles
 */
long intersection(int r1, int r2, int d) {
    long rtn = 0;
    for (int i = d - r2; i <= r1; i++) {
        int num = (int) min(sqrt(r1 * r1 - i * i), sqrt(r2 * r2 - (d - i) * (d - i)));
        rtn += num;
    }
    return max(0l, 2 * rtn + r1 + r2 - d + 1);
}

void d14() {
    int _;
    cin >> _;

    while (_--) {
        int n, m;
        cin >> n >> m;

        vector<pair<int, int>> c(n);
        for (int i = 0; i < n; i++) {cin >> c[i].first;}
        for (int i = 0; i < n; i++) {cin >> c[i].second;}

        // Ensuring x positions are increasing
        sort(c.begin(), c.end(), comp);

        int prev = 0;
        long rtn = 0;
        for (int i = 1; i < n; i++) {
            if (c[prev].first + c[prev].second >= c[i].first + c[i].second && c[prev].first - c[prev].second <= c[i].first - c[i].second) {
                // Case for consumption
                // Do Nothing
            } else if (c[prev].first + c[prev].second < c[i].first - c[i].second || c[prev].first - c[prev].second > c[i].first + c[i].second) {
                // No overlap
                rtn += complete(c[prev].second);
                prev = i;
            } else {
                // Overlap
                rtn += complete(c[prev].second);
                rtn -= intersection(c[prev].second, c[i].second, abs(c[i].first - c[prev].first));
                prev = i;
            }
        }
        rtn += complete(c[prev].second);
        cout << rtn << endl;
    }
}