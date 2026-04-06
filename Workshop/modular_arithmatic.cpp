#include <bits/stdc++.h>

using namespace std;

long long inverse(long long k, long long m) {
    return k <= 1 ? k : m - (long long)(m / k) * inverse(m % k, m) % m;
}

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
    while (1) {
        long long int n, t;
        cin >> n >> t;

        if (n == 0) exit(0); 

        for (int i = 0; i < t; i++) {
            long long int x, y;
            char op;
            cin >> x >> op >> y;

            long long int res;
            if (op == '/') {
                long long int l, k;
                long long int gcd = extendedEuclidean(y, n, l, k);
                res = (gcd != 1 ? -1 : (x * inverse(y, n)) % n);
            } else if (op == '+') {
                res = (x + y) % n;
            } else if (op == '*') {
                res = ((x % n) * (y % n)) % n;
            } else {
                res = (x - y + n) % n;
            }

            cout << res << "\n";
        }
    }
}