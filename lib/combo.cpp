#include <bits/stdc++.h>

using namespace std;


const double EPSILON = 0.0001;

/**
 * Computes n choose k for small result values
 * O(k)
 */
long long nCk(long long n, long long k) {
    double res = 1;
    for (long long i = 1; i <= k; ++i)
        res = res * (n - k + i) / i;
    return (long long)(res + EPSILON);
}

/**
 * Computes n choose k with an array of factorials and inverse factorials
 * both f and inv_f must have length of at least n
 * O(1)
 */
long long nCkFast(long long n, long long k, const vector<long long>& f, const vector<long long>& inv_f, long long m) {
    return (((f[n] * inv_f[k]) % m) * inv_f[n - k]) % m;
}

/**
 * Computes a vector of length n + 1, where
 * factorial[i] = i! % mod
 * O(n)
 */
vector<long long> factorial(long long n, long long mod) {
    vector<long long> rtn(n);
    rtn[0] = 1;

    for (long long i = 1; i <= n; i++) {
        rtn[i] = (rtn[i - 1] * i) % mod;
    }

    return rtn;
}

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
 * Computes the n-th catalan number mod m
 * The factorial and inverse factorial arrays must be at least size 2n
 * O(1)
 */
long long catalan(long long n, long long m, const vector<long long>& f, const vector<long long>& inv_f) {
    return nCkFast(2 * n, n, f, inv_f, m) / (n + 1);
}