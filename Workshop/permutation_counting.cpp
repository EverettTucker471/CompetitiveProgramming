//
// Created by legoe on 6/26/2024.
//

#include <iostream>
#include <cmath>

bool works(const long long int a[], long long int k, long long int val, int n) {
    long long int rtn = 0;
    for (int i = 0; i < n; i++) {
        rtn += std::max((long long int) 0, val - a[i]);
    }
    return rtn <= k;
}

void permutation_counting() {
    int _;
    std::cin >> _;

    for (; _ > 0; _--) {
        int n;
        long long int k;
        std::cin >> n >> k;

        long long int a[n];
        for (long long int& x : a) {
            std::cin >> x;
        }

        long long int left = 0;
        long long int right = 2 * 10e12;

        while (left < right) {
            long long int mid = (left + right + 1) / 2;

            if (works(a, k, mid, n)) {
                left = mid;
            } else {
                right = mid - 1;
            }
        }

        std::cout << left << std::endl;
    }
}
