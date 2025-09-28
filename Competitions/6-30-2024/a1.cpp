//
// Created by legoe on 6/30/2024.
//

#include <iostream>

void a1() {
    int _;
    std::cin >> _;

    for (; _ > 0; _--) {
        int n, k;
        std::cin >> n >> k;

        std::cout << (n - 1) * k + 1 << std::endl;
    }
}
