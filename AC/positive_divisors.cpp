#include <bits/stdc++.h>

using namespace std;

void positive_divisors() {
    long long n;
    cin >> n;

    // Computes the factorization of a number in sqrt(n)
    map<long long, int> factorization;
    for (long long i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            factorization[i]++;
            n /= i;
            i = 1;
        }
    }
    // Adding the final prime number
    factorization[n]++;

    // Go through the factorization and generate the numbers

    // Still don't know the cases where this requires a set
    set<long long> factors;
    factors.insert(1LL);
    vector<long long> temp;
    for (pair<long long, int> x : factorization) {
        temp.clear();
        for (long long y : factors) {
            long long num = 1LL;
            for (int i = 1; i <= x.second; i++) {
                num *= x.first;
                temp.push_back(y * num);
            }
        }
        for (long long z : temp) factors.insert(z);
    }

    for (long long x : factors) cout << x << endl;
}