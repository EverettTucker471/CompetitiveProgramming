#include <bits/stdc++.h>

using namespace std;

/**
 * Each item can only either appear or not in the knapsack
 */
int binaryKnapsack(int n, int W, const vector<int>& w, const vector<int>& v) {
    vector<int> dp(W + 1, 0);
    for (int i = 1; i <= n; i++) {
        for (int j = W; j >= w[i - 1]; j--) {
            dp[j] = max(dp[j], dp[j - w[i - 1]] + v[i - 1]);
        }
    }
    return dp[W];
}

/**
 * Each item can be in the knapsack multiple times
 */
int completeKnapsack(int n, int W, const vector<int>& w, const vector<int>& v) {
    vector<int> dp(W + 1, 0);
    for (int i = 1; i <= n; i++) {
        for (int j = w[i - 1]; j <= W; j++) {
            dp[j] = max(dp[j], dp[j - w[i - 1]] + v[i - 1]);
        }
    }
    return dp[W];
}
