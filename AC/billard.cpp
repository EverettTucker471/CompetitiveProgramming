#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using dd = int;
using ii = pair<dd, dd>;
using vi =  vector<dd>;
using vii = vector<ii>;
using vvi = vector<vi>;
using vvii = vector<vii>;

void billard() {
    while (true) {
        long double a, b, s, m, n;
        cin >> a >> b >> s >> m >> n;
        if (a == 0) {break;}

        long double theta = std::atan((b * n) / (a * m)) * 180 / M_PI;
        long double v = std::sqrt(a * a * m * m + b * b * n * n) / s;
        printf("%.2Lf ", theta);
        printf("%.2Lf \n", v);
    }
}