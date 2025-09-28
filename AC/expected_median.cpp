#include <iostream>
#include <cmath>

using namespace std;

// This was a hard one for sure, huge in the number theory computation side.

// Time complexity is slightly under log(m)
unsigned long long int inv(unsigned long long int a, int m) {
    return a <= 1 ? a : m - static_cast<unsigned long long int>(m / a) * inv(m % a, m) % m;
}

void expected_median() {
    int _;
    cin >> _;

    while (_--) {
        int n, k;
        int m = 0;
        cin >> n >> k;
        for (int i = 0; i < n; i++) {bool a; cin >> a; m += a;}

        int l = (k + 1) / 2;
        int u = std::min(m, k);
        const int gargantua = 1e9 + 7;
        unsigned long long int rtn = 0;

        // Precompute Factorials up to std::max(n, m, k)
        unsigned long long int fact[std::max(n, std::max(m, k)) + 1];
        fact[0] = 1;
        for (int i = 1; i < std::max(n, std::max(m, k)) + 1; i++) {
            fact[i] = (fact[i - 1] * i) % gargantua;
        }

        // There's some crazy stuff with computing modular inverses here as well
        for (int i = l; i <= u; i++) {
            if (n - m >= k - i) {
                unsigned long long int top = (fact[m] * fact[n - m]) % gargantua;
                unsigned long long int bottom = (fact[i] * fact[m - i]) % gargantua;
                bottom = (bottom * fact[k - i]) % gargantua;
                bottom = (bottom * fact[n - m - k + i]) % gargantua;
                rtn += (top * inv(bottom, gargantua)) % gargantua;
                rtn %= gargantua;
            }
        }

        cout << rtn << endl;
    }
}
