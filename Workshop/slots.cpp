#include<vector>
#include<iostream>
#include<cmath>
#include <algorithm>
#include <climits>

using namespace std;

double magnitude(pair<double, double> x) {
    return sqrt(x.first * x.first + x.second * x.second);
}

double cross_product(pair<double, double> a, pair<double, double> b) {
    return a.first * b.second - a.second * b.first;
}

void slots() {
    // Find base distance for each side
    int n;
    cin >> n;

    vector<pair<double, double>> v(n);
    for (auto& x : v) {
        cin >> x.first;
        cin >> x.second;
    }

    double rtn = INT_MAX;
    for (int i = 0; i < n; i++) {
        pair<double, double> edge = {v[(i + 1) % n].first - v[i].first, v[(i + 1) % n].second - v[i].second};
        double dist = 0;
        for (int j = i + 2; j < i + n; j++) {
            pair<double, double> line = {v[j % n].first - v[i].first, v[j % n].second - v[i].second};
            double res = abs(cross_product(edge, line)) / magnitude(edge);
            dist = max(dist, res);
        }
        rtn = min(rtn, dist);
    }

    cout << rtn << endl;
}