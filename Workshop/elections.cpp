//
// Created by legoe on 6/25/2024.
//

#include <iostream>
#include <cmath>
#include <algorithm>

void elections() {
    int _;
    std::cin >> _;

    for (; _ > 0; _--) {
        int n, c;
        std::cin >> n >> c;
        int arr[n];
        long long int partials[n];

        for (int& x : arr) {
            std::cin >> x;
        }

        // Finding the unique zero index
        int zero_index = 0;
        int max = INT_MIN;
        for (int i = 0; i < n; i++) {
            if (arr[i] > max) {
                zero_index = i;
                max = arr[i];
            }
        }

        // Creating Partials
        partials[0] = arr[0];
        for (int i = 1; i < n; i++) {
            partials[i] = arr[i] + partials[i - 1];
        }

        for (int i = 0; i < n; i++) {
            if (i == zero_index) {
                std::cout << 0 << (i < n - 1 ? " " : "" );
                continue;
            }

            long long val = c + arr[i];
            if (i > 0) {val += partials[i - 1];}

            // use binary searchDFS to find the highest i < n such that val + partials[n - 1] - partials[i] >= arr[i]
            int left = i + 1;
            int right = n - 1;
            while (left < right) {
                int mid = (left + right + 1) / 2;

                if (val + partials[n - 1] - partials[mid] >= arr[mid - 1]) {
                    left = mid;
                } else {
                    right = mid - 1;
                }
            }

            std::cout << std::max(n - 1 - left, 0) + i << (i < n - 1 ? " " : "" );
        }
        std::cout << std::endl;
    }
}