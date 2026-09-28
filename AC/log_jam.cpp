#include <bits/stdc++.h>

using namespace std;

double d(pair<double, double> x, pair<double, double> y) {
    return (y.first - x.first) * (y.first - x.first) + 
        (y.second - x.second) * (y.second - x.second);
}

int main() {
    pair<int, int> ks, os, ke, oe;
    cin >> ks.first >> ks.second;
    cin >> os.first >> os.second;
    cin >> ke.first >> ke.second;
    cin >> oe.first >> oe.second;

    pair<double, double> kv, ov;
    kv.first = ke.first - ks.first;
    kv.second = ke.second - ks.second;
    ov.first = oe.first - os.first;
    ov.second = oe.second - os.second;

    double dist = 0;
    double step = 0.00001;
    for (double x = 0; x <= 1; x += step) {
        dist = max(dist, d(
            {kv.first * x + ks.first, kv.second * x + ks.second}, 
            {ov.first * x + os.first, ov.second * x + os.second}
        ));
    }

    printf("%.8f\n", sqrt(dist));
}