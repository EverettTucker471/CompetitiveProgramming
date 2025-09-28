//
// Created by legoe on 6/27/2024.
//

// Losercity Problem

#include <iostream>

int extra(std::string a, std::string b, int n, int m, int index) {
    // Store the position of the progress in string a
    int left = 0;
    int right = n - 1;

    // Store the position of the progress in string b
    int i1 = index;
    int i2 = index + 1;

    while (left < right) {
        if (0 <= i1 < m && 0 <= left < n) {
            if (a[left] == b[i1]) {
                i1--;
            }
        }
        if (0 <= i2 < m && 0 <= right < n) {
            if (a[right] == b[i2]) {
                i2++;
            }
        }
        left++;
        right--;
    }
    return i1 + m - i2 + 1;
}

void problem2() {
    int _;
    std::cin >> _;

    for (; _ > 0; _--) {
        std::string a, b;
        std::cin >> a >> b;

        int n = a.size();
        int m = b.size();

        int rtn = INT_MAX;

        for (int i = -1; i < n; i++) {
            rtn = std::min(rtn, extra(a, b, n, m, i));
        }

        std::cout << rtn + n << std::endl;
    }
}
