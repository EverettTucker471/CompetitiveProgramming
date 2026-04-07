#include <bits/stdc++.h>

using namespace std;

/**
 * Returns the gcd of a and b, and
 * returns x, y by reference which satisfy
 * ax + by = gcd(a, b)
 */
long long extendedEuclidean(long long a, long long b, long long& x, long long& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    long long x1, y1;
    long long d = extendedEuclidean(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}


int main() {
    double total, pita, pizza;
    cin >> total >> pita >> pizza;

    long long p = (long long) std::round(total * 100);
    long long t = (long long) std::round(pita * 100);
    long long z = (long long) std::round(pizza * 100);

    long long x, y;
    long long gcd = extendedEuclidean(t, z, x, y);
    if (p % gcd != 0) exit(0);
    p /= gcd;
    t /= gcd;
    z /= gcd;

    extendedEuclidean(t, z, x, y);
    pair<long long, long long> particular = {p * x, p * y};
    // cout << particular.first << " " << particular.second << "\n";

    vector<pair<long long, long long>> solns;
    for (long long k = -particular.first / z; k <= particular.second / t; k++) {
        pair<long long, long long> inst = {
            particular.first + k * z,
            particular.second - k * t 
        };
        if (inst.first >= 0 && inst.second >= 0) {
            solns.push_back(inst);
        } 
    }

    for (pair<long long, long long> x : solns) {
        cout << x.first << " " << x.second << "\n";
    }
}