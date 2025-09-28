//
// Created by legoe on 7/3/2024.
//

#include <iostream>
#include <cmath>

int findMax(int r, long long int bound) {
    // Returns the maximum a such that bottom <= a^2 + b^2 < top
    int left = 0;
    int right = r;

    while (left < right) {
        long long int mid = (left + right + 1) / 2;

        if (mid * mid < bound) {
            left = mid;
        } else {
            right = mid - 1;
        }
    }
    return left;
}

int findMin(int r, long long int bound) {
    // Returns the minimum a such that bottom <= a^2 + b^2 < top
    int left = 0;
    int right = r;

    while (left < right) {
        long long int mid = (left + right) / 2;

        if (bound <= mid * mid) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    return left;
}

void circle_perimeter() {
    int _;
    std::cin >> _;

    for (; _ > 0; _--) {
        long long int r;
        std::cin >> r;

        long long int rtn = 0;
        long long int top = (r + 1) * (r + 1);
        long long int bottom = r * r;
        for (long long int b = 0; b <= r; b++) {
            rtn += findMax(r, top - b * b) - findMin(r, bottom - b * b) + 1;
        }

        std::cout << 4 * (rtn - 1) << std::endl;
    }
}
