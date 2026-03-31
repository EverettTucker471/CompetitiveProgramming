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
    // This is an LCM problem
    
    long long int p, q, s;
    cin >> p >> q >> s;

    long long int lcm = (p * q) / gcd(p, q);
    cout << (lcm > s ? "no" : "yes") << "\n";
}