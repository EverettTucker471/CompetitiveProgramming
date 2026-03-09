#include <bits/stdc++.h>

using namespace std;

bool checkPrime(long long int n) {
    for (long long int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    
    return true;
}

int main() {
    int n;
    cin >> n;
    while (n > 0) {
        long long int res;
        bool prime = checkPrime(n);
        for (long long int i = 2 * n + 1; i < LONG_LONG_MAX; i++) {
            if (checkPrime(i)) {
                res = i;
                break;
            }
        }

        if (prime) {
            cout << res << '\n';
        } else {
            cout << res << " (" << n << " is not prime)\n";
        }

        cin >> n;
    }
}