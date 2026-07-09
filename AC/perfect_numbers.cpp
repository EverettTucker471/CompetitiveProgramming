#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    while (cin >> n) {
        map<long long int, int> divisors;
        long long int n_save = n;
        long long int i = 2;
        for (; i * i <= n; i++) {
            if (n % i == 0) {
                n /= i;
                divisors[i]++;
                i = 1;
            }
        }

        if (n > 1) divisors[n]++;

        long long int sum = 1;
        for (auto x : divisors) {
            sum *= (pow(x.first, x.second + 1) - 1) / (x.first - 1);
        }
        n = n_save;
        if (sum - n == n) {
            cout << n << " perfect\n";
        } else if (abs(sum - 2 * n) <= 2) {
            cout << n << " almost perfect\n";
        } else {
            cout << n << " not perfect\n";
        }
    }
}