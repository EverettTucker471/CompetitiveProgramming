//
// Created by legoe on 6/23/2024.
//

#include <iostream>
#include <cmath>

long long int findPower(int b, int p, int m) {
    if (p == 0) {return 1;}
    if (p == 1) {return b % m;}
    int n = std::floor(std::log2(p)) + 1;
    long long int residues[n];
    residues[0] = b;
    for (int i = 1; i < n; i++) {
        residues[i] = (residues[i - 1] * residues[i - 1]) % m;
    }
    long long int rtn = 1;
    for (int i = 0; i < n; i++) {
        if (p % 2) {
            rtn = (rtn * residues[i]) % m;
        }
        p /= 2;
    }

    return rtn;
}


void d_function() {
    // The answer is (floor(9 / k) + 1)^r - (floor(9 / k) + 1)^l % 1000000007 if k < 10 else 0

    int _;
    std::cin >> _;
    int mod = 1000000007;

    for (; _ > 0; _--) {
        int l, r, k;
        std::cin >> l >> r >> k;

        if (k > 9) {
            std::cout << 0 << std::endl;
            continue;
        }

        int base = 9 / k + 1;
        std::cout << (findPower(base, r, mod) - findPower(base, l, mod) + mod) % mod << std::endl;
    }
}
