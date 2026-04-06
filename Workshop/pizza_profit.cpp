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

    long long p = (int) std::round(total * 100);
    long long t = (int) std::round(pita * 100);
    long long z = (int) std::round(pizza * 100);

    long long x, y;
    long long gcd = extendedEuclidean(t, z, x, y);
    long long scale = p / gcd;
    pair<long long, long long> particular = {scale * x, scale * y};

    long long s1 = z / gcd;
    long long s2 = t / gcd;
    //cout << particular.first << " " << particular.second << endl;
    long long LIM = 1000000;
    vector<pair<long long, long long>> solns;
    for (long long int k = -LIM; k < LIM; k++) {
        pair<long long, long long> inst = {
            particular.first + k * s1,
            particular.second - k * s2 
        };
        if (inst.first >= 0 && inst.second >= 0) {
            solns.push_back(inst);
        } 
    }

    sort(solns.begin(), solns.end());
    for (auto x : solns) {
        cout << x.first << " " << x.second << "\n";
    }
}