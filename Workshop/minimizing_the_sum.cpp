//
// Created by legoe on 6/26/2024.
//

#include <iostream>

int a[300000];
int dp[300001][11];

int find(int n, int k) {
    if (n == 0) {return 0;}
    if (dp[n][k] != 0) {return dp[n][k];}

    // State Equation...

    return 0;
}

void minimizing_the_sum() {
    int _;
    std::cin >> _;

    for (; _ > 0; _--) {
        int n, k;
        std::cin >> n >> k;

        for (int i = 0; i < n; i++) {
            std::cin >> a[i];
        }

        std::cout << find(n, k);
    }
}
