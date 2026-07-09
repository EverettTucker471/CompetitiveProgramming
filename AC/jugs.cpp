#include <bits/stdc++.h>

using namespace std;

long long gcd(long long a, long long b) {
    while (b) {
        long long r = a % b;
        a = b;
        b = r;
    }

    return a;
}

int main() {
    int _;
    cin >> _;

    while (_--) {
        long long int a, b, d;
        cin >> a >> b >> d;

        long long x = gcd(a, b);
        cout << (d % x == 0 ? "Yes" : "No") << "\n";
    }
}