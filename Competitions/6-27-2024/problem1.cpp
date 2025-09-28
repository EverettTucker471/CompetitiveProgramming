//
// Created by legoe on 6/27/2024.
//

#include <iostream>

void problem1() {
    int _;
    std::cin >> _;

    for (; _ > 0; _--) {
        int x, y;
        std::cin >> x >> y;

        std::cout << ((y >= -1) ? "YES" : "NO") << std::endl;
    }
}
