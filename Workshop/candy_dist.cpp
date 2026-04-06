#include <bits/stdc++.h>

using namespace std;

long long inverse(long long k, long long m) {
    return k <= 1 ? k : m - (long long)(m / k) * inverse(m % k, m) % m;
}

long long gcd(long long a, long long b) {
    if (a == 0) {
        return b;
    }
    return gcd(b % a, a);
}

int main() {
    int _;
    cin >> _;

    while (_--) {
        long long int k, c;
        cin >> k >> c;

        if (gcd(k, c) == 1) {
            long long inv = inverse(c, k);
            if (inv > 1e9) {
                cout << "IMPOSSIBLE\n";
            } else {
                cout << inv << '\n';
            }
        } else {
            cout << "IMPOSSIBLE\n";
        }
    }
}