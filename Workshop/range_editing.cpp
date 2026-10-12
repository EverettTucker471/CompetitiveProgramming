#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    vector<int> a(n);
    for (auto& x : a) cin >> x;

    // dp[i][j] is min ways to color from index i to index j (inclusive)
    vector<vector<int>> dp(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) dp[i][i] = 1;

    /**
     * also include color in dp
     * bottom-up going in incresing length of the interval size
     * 
     */
}