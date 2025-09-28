//
// Created by legoe on 7/21/2024.
//

#include <iostream>
#include <cmath>
#include <vector>

void final_countdown() {
    // This is sum(digit * 1 string)
    // You can compute this with a prefix sum from left to right, and then carry from right to left
    // AC all day

    int _;
    std::cin >> _;

    while (_--) {
        int n;
        std::cin >> n;

        std::vector<int> partials(n + 1, 0);

        for (int i = 1; i <= n; i++) {
            char val;
            std::cin >> val;
            partials[i] = val + partials[i - 1] - '0';
        }

        for (int i = n; i > 0; i--) {
            partials[i - 1] += (partials[i] - (partials[i] % 10)) / 10;
            partials[i] %= 10;
        }

        int index = 0;
        while (partials[index] == 0) {index++;}
        while (index <= n) {
            std::cout << partials[index];
            index++;
        }
        std::cout << std::endl;
    }
}
