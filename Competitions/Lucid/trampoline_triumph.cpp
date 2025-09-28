#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using dd = int;
using ii = pair<dd, dd>;
using vi =  vector<dd>;
using vii = vector<ii>;
using vvi = vector<vi>;
using vvii = vector<vii>;

double g(double x, double f) {
    return (6 - 2 * f * sin(x / 2) - 2 * f * sin(x / 5) - 2 * f * sin(x / 7)) * (0.9 + (1 + sin(x * f / 3)) / 20);
}

double find_max(double l, double r, double p_factor) {
    while (r - l > 0.000000001) {
        double m1 = (r + 2 * l) / 3;
        double m2 = (2 * r + l) / 3;

        double v1 = g(m1, p_factor);
        double v2 = g(m2, p_factor);
        if (v1 > v2) {
            r = m2;
        } else {
            l = m1;
        }
    }
    return g((r + l) / 2, p_factor);
}

bool comp(vector<int> a, vector<int> b) {
    return a[1] > b[1];
}

void solve() {
    int n;
    cin >> n;
    double p_factors[n];
    for (auto& x : p_factors) {
        cin >> x;
    }

    int m;
    cin >> m;
    pair<double, double> queries[m];
    for (int i = 0; i < m; i++) {
        cin >> queries[i].first;
        cin >> queries[i].second;
    }

    vector<vector<int>> scores(n, vector<int>(2, 0));
    for (int i = 0; i < n; i++) {
        scores[i][0] = i;
    }

    for (int i = 0; i < m; i++) {
        int index = 0;
        double max = 0;
        for (int j = 0; j < n; j++) {
            double val = find_max(queries[i].first, queries[i].second, p_factors[j]);
            if (val > max) {
                index = j;
                max = val;
            }
        }
        scores[index][1]++;
    }

    sort(scores.begin(), scores.end(), comp);
    for (int i = 0; i < n; i++) {
        cout << scores[i][0] + 1 << " " << scores[i][1] << endl;
    }
}