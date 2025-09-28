//
// Created by legoe on 6/30/2024.
//

#include <iostream>
#include <vector>
#include <algorithm>

void b1() {
    int _;
    std::cin >> _;

    for (; _ > 0; _--) {
        int n;
        std::cin >> n;
        int a[n];

        for (auto& x : a) {
            std::cin >> x;
        }

        // Partial Maximums?

        int pmax[n];
        pmax[0] = a[0];
        for (int i = 1; i < n; i++) {
            pmax[i] = std::max(pmax[i - 1], a[i]);
        }

        std::vector<int> diff;
        for (int i = 0; i < n; i++) {
            if (pmax[i] > a[i]) {diff.push_back(pmax[i] - a[i]);}
        }

        std::sort(diff.begin(), diff.end());
        long long int rtn = 0;
        int cur = 0;
        int m = diff.size();
        for (int i = 0; i < m; i++) {
            rtn += (diff[i] - cur) * (m - i + 1);
            cur = std::max(cur, diff[i]);
        }
        std::cout << rtn << std::endl;
    }
}
