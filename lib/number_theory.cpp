#include <vector>
#include <iostream>
#include <unordered_map>
#include <map>
#include <unordered_set>
#include <set>
#include <cmath>
#include <algorithm>
#include <climits>
#include <numeric>

using namespace std;

/**
 * Computes the greatest common divisor of a and b
 * a * b = lcm(a, b) * gcd(a, b)
 * O(loga)
 */
long long gcd(long long a, long long b) {
    while (b) {
        long long r = a % b;
        a = b;
        b = r;
    }

    return a;
}

/**
 * Returns a vector of length n + 1 where
 * primes[i] = true if i is prime, else 0
 * O(nloglogn)
 */
vector<bool> primes(int n) {
    vector<bool> rtn(n + 1, true);
    rtn[0] = false;
    rtn[1] = false;
    for (int i = 2; i * i <= n; i++) {
        if (rtn[i]) {
            for (int j = i * i; j <= n; j += i) {
                rtn[j] = false;
            }
        }
    }

    return rtn;
}

/**
 * Computes the prime factorization of n, sorted in ascending order
 * O(sqrtn)
 */
vector<long long> factorization(long long n) {
    vector<long long> factors;

    long long i = 2;
    for (; i * i <= n; i++) {
        if (n % i == 0) {
            factors.push_back(i);
            n /= i;
            i = 1;
        }
    }

    if (n > 1) factors.push_back(n);
    return factors;
}

/**
 * Returns an array of length n + 1 where
 * divisorCount[i] = the number of divisors of i
 * O(nlogn)
 */
vector<int> divisorCount(int n) {
    vector<int> rtn(n + 1, 1);
    for (int i = 2; i <= n; i++) {
        for (int j = i; j <= n; j += i) {
            rtn[j]++;
        }
    }

    return rtn;
}

/**
 * Returns an array of length n + 1 where
 * divisorSum[i - 1] = the sum of all divisors of i mod m
 */
vector<long long> divisorSum(int n, int m) {
    vector<long long> rtn(n + 1, 1);
    for (int i = 2; i <= n; i++) {
        for (int j = i; j <= n; j += i) {
            rtn[j] = (rtn[j] + i) % m;
        }
    }

    return rtn;
}

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