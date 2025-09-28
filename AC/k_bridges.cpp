//
// Created by legoe on 7/4/2024.
//

#include <iostream>
#include <cmath>
#include <deque>

long long int findMin(int m, int d, const int arr[]) {
    std::deque<long long int> deque;  // deque stores indices in ascending order based on their values in dp
    long long int dp[m];
    dp[0] = 1;
    deque.push_back(0);
    for (int i = 1; i < m; i++) {
        dp[i] = arr[i] + dp[deque.front()] + 1;
        while (deque.front() < i - d) {
            deque.pop_front();
        }
        while (dp[deque.back()] > dp[i]) {
            deque.pop_back();
        }
        deque.push_back(i);
    }

    return dp[m - 1];
}

void k_bridges() {
    int _;
    std::cin >> _;

    for (; _ > 0; _--) {
        int n, m, k, d;
        std::cin >> n >> m >> k >> d;
        int arr[n][m];

        for (auto& x : arr) {
            for (auto& y : x) {
                std::cin >> y;
            }
        }

        long long int results[n];
        for (int i = 0; i < n; i++) {
            results[i] = findMin(m, d, arr[i]);
        }

        long long int rtn = LONG_LONG_MAX;
        long long int cur = 0;

        for (int i = 0; i < k; i++) {
            cur += results[i];
        }
        for (int i = k; i < n; i++) {
            rtn = std::min(rtn, cur);
            cur += results[i];
            cur -= results[i - k];
        }

        std::cout << std::min(rtn, cur) << std::endl;
    }
}
