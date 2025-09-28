//
// Created by legoe on 6/24/2024.
//

#include <iostream>
#include <cmath>

void magnitude_easy() {
    int _;
    std::cin >> _;

    for (; _ > 0; _--) {
        int n;
        std::cin >> n;
        int arr[n];

        for (int& x : arr) {
            std::cin >> x;
        }

        long long int dp_min[n];
        long long int dp_max[n];

        dp_min[0] = arr[0];
        dp_max[0] = std::abs(arr[0]);
        for (int i = 1; i < n; i++) {
            dp_min[i] = std::min(dp_min[i - 1] + arr[i], dp_max[i - 1] + arr[i]);
            dp_max[i] = std::max(std::abs(dp_min[i - 1] + arr[i]), std::abs(dp_max[i - 1] + arr[i]));
        }

        std::cout << dp_max[n - 1] << std::endl;
    }
}
