#include <bits/stdc++.h>

using namespace std;

double dist_sq(pair<double, double> x, pair<double, double> y) {
    return (x.first - y.first) * (x.first - y.first) +
    (x.second - y.second) * (x.second - y.second);
}

bool inside(pair<double, double> p, pair<double, double> c, double r_sq) {
    return dist_sq(p, c) <= r_sq;
}

int main() {
    int _;
    cin >> _;

    while (_--) {
        int n;
        cin >> n;

        vector<string> colors(n);
        vector<vector<double>> a(n, vector<double>(3));
        for (int i = 0; i < n; i++) {
            cin >> a[i][0] >> a[i][1] >> a[i][2];
            cin >> colors[i];
        }

        int m;
        cin >> m;
        vector<pair<double, double>> queries(m);
        for (auto& x : queries) cin >> x.first >> x.second;

        for (auto q : queries) {
            string ans = "white";
            for (int i = n - 1; i >= 0; i--) {
                if (inside({a[i][0], a[i][1]}, q, a[i][2] / M_PI)) {
                    ans = colors[i];
                    break;
                }
            }
            cout << ans << '\n';
        }
    }
}