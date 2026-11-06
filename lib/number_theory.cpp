#include <bits/stdc++.h>
using namespace std;

/**
 * Computes the modular inverse of k mod m
 * O(logk)
 */
long long inverse(long long k, long long m) {
    return k <= 1 ? k : m - (long long)(m / k) * inverse(m % k, m) % m;
}

/**
 * Computes the modular inverses of all numbers in [1, m - 1] mod m
 * inverseArray(m)[i] = the modular inverse of i mod m
 * O(m)
 */
vector<long long> inverseArray(long long m) {
    vector<long long> rtn(m);
    rtn[1] = 1;

    for (long long i = 2; i < m; i++) {
        rtn[i] = m - (long long)(m / i) * rtn[m % i] % m;
    }

    return rtn;
}

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
 * For a single number, use factorization and math
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

/**
 * Used to solve a system of congruences of the form:
 * x % m_1 = a_1 % m_2
 * x % m_2 = a_2 % m_2
 * ...
 * x % m_n = a_n % m_n
 * @param congs is a vector of {a_i, m_i} pairs
 * @return x, the solution to the congruences
 */
long long chinese_remainder_theorem(vector<pair<long, long>> const& congs) {
    long M = 1;
    for (auto const& cong : congs) M *= cong.second;

    long sol = 0;
    for (auto const& cong : congs) {
        long a_i = cong.first;
        long M_i = M / cong.second;
        long N_i = inverse(M_i, cong.second);
        sol = (sol + ((a_i * M_i) % M) * N_i) % M;
    }

    return sol;
}