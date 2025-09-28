//
// Created by legoe on 6/26/2024.
//

#include <iostream>
#include <cmath>

void find_the_car() {
    int _;
    std::cin >> _;

    for (; _ > 0; _--) {
        int n, k, q;
        std::cin >> n >> k >> q;
        int a[k + 1], b[k + 1];
        a[0] = 0;
        b[0] = 0;

        for (int i = 1; i < k + 1; i++) {
            std::cin >> a[i];
        }
        for (int i = 1; i < k + 1; i++) {
            std::cin >> b[i];
        }

        // Compute speeds first, then do a b-searchDFS for each query
        // These are distance, time pairs
        std::pair<int, int> s[k];
        for (int i = 0; i < k; i++) {
            s[i].first = b[i + 1] - b[i];
            s[i].second = a[i + 1] - a[i];
        }

        for (int i = 0; i < q; i++) {
            int query;
            std::cin >> query;

            int left = 0;
            int right = k - 1;

            while (left < right) {
                int mid = (left + right + 1) / 2;

                if (query > a[mid]) {
                    left = mid;
                } else {
                    right = mid - 1;
                }
            }

            // Finally!!!
            long long int num = ((long long int) s[left].first * (query - a[left])) / s[left].second;
            std::cout << b[left] + num << (i < q - 1 ? " " : "");
        }
        std::cout << std::endl;
    }
}