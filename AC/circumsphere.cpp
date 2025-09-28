#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using dd = int;
using ii = pair<dd, dd>;
using vi =  vector<dd>;
using vii = vector<ii>;
using vvi = vector<vi>;
using vvii = vector<vii>;

double det(vector<double> c1, vector<double> c2, vector<double> c3) {
    double rtn1 = c1[0] * (c2[1] * c3[2] - c2[2] * c3[1]);
    double rtn2 = -c2[0] * (c1[1] * c3[2] - c1[2] * c3[1]);
    double rtn3 = c3[0] * (c1[1] * c2[2] - c1[2] * c2[1]);
    return rtn1 + rtn2 + rtn3;
}

double dot(vector<double> a, vector<double> b) {
    return a[0] * b[0] + a[1] * b[1] + a[2] * b[2];
}

void circumcircle() {
    vector<vector<double>> points(4, vector<double>(3));
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> points[i][j];
        }
    }

    // Define three planes, then find their intersection
    // This is the center of the circumsphere
    vector<double> n1 = {points[1][0] - points[0][0], points[1][1] - points[0][1], points[1][2] - points[0][2]};
    vector<double> n2 = {points[2][0] - points[0][0], points[2][1] - points[0][1], points[2][2] - points[0][2]};
    vector<double> n3 = {points[3][0] - points[0][0], points[3][1] - points[0][1], points[3][2] - points[0][2]};

    vector<double> a = {(points[1][0] + points[0][0]) / 2, (points[1][1] + points[0][1]) / 2, (points[1][2] + points[0][2]) / 2};
    vector<double> b = {(points[2][0] + points[0][0]) / 2, (points[2][1] + points[0][1]) / 2, (points[2][2] + points[0][2]) / 2};
    vector<double> c = {(points[3][0] + points[0][0]) / 2, (points[3][1] + points[0][1]) / 2, (points[3][2] + points[0][2]) / 2};

    vector<double> res = {dot(a, n1), dot(b, n2), dot(c, n3)};

    double d = det({n1[0], n2[0], n3[0]}, {n1[1], n2[1], n3[1]}, {n1[2], n2[2], n3[2]});
    double dx = det(res, {n1[1], n2[1], n3[1]}, {n1[2], n2[2], n3[2]});
    double dy = det({n1[0], n2[0], n3[0]}, res, {n1[2], n2[2], n3[2]});
    double dz = det({n1[0], n2[0], n3[0]}, {n1[1], n2[1], n3[1]}, res);

    printf("%f8", dx / d);
    cout << endl;
    printf("%f8", dy / d);
    cout << endl;
    printf("%f8", dz / d);
}