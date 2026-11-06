#include <bits/stdc++.h>

using namespace std;

/**
 * Assume that a > b
 */
long gcd(long long a, long long b) {
    return (b == 0 ? a : gcd(b, a % b));
}

int main() {
    int n;
    cin >> n;

    int SIZE = 100000;

    int res = 1;
    for (int i = 0; i < SIZE; i++) {
        int low = max(n / 2 - i, 1);
        int high = min(n / 2 + i, n - 1);

        long x = gcd(n, low);
        // cout << "Low: " << low << " " << x << '\n';
        if (x == 1) {
            res = low;
            break;
        }

        long y = gcd(n, high);
        // cout << "High: " << high << " " << y << '\n';
        if (y == 1) {
            res = high;
            break;
        }
    }

    cout << res << '\n';
}