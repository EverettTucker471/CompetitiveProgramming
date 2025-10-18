#include<vector>
#include<iostream>
#include<unordered_map>
#include<map>
#include<unordered_set>
#include<set>
#include<cmath>
#include <algorithm>
#include <climits>
#include <numeric>

using namespace std;


// Didn't even get to submit this one, but pretty confident in it

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

void mhc3() {
    int _;
    cin >> _;

    for (int c = 0; c < _; c++) {
        long long n, a, b;
        cin >> n >> a >> b;
        vector<long long> factors = factorization(b);
        n *= 2;  // Compensation for now

        // Pad with ones at the start, sort later
        while (factors.size() < n) factors.push_back(1);

        // Condensing
        while (factors.size() > n) {
            factors[factors.size() - 2] *= factors.back();
            factors.pop_back();
        }

        std::sort(factors.begin(), factors.end());

        printf("Case #%d: ", c + 1);
        for (auto x : factors) printf("%lld ", x);
        printf("\n");
    }
}

void easy() {
    int _;
    cin >> _;

    for (int c = 0; c < _; c++) {
        long long n, a, b;
        cin >> n >> a >> b;
        n *= 2;  // Compensation for now

        printf("Case #%d: ", c + 1);
        for (int i = 0; i < n - 1; i++) printf(" 1");
        printf(" %lld\n", b);
    }
}

int main() {
    easy();
    return 0;
}