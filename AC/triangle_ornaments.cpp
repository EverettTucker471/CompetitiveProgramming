#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<vector<int>> triangles(n, vector<int>(3, 0));
    for (auto& x : triangles) {
        for (auto& y : x) cin >> y;
    }

    // Compute the centroid
    double rtn = 0;
    for (auto t : triangles) {
        double a = t[0];
        double b = t[1];
        double c = t[2];
        double s = (a + b + c) / 2;
        double area = sqrt(s * (s - a) * (s - b) * (s - c));
        double z = sqrt((a * a + b * b) / 2 - c * c / 4);
        rtn += (area * 2) / z;
    }

    printf("%.8lf\n", rtn);
}