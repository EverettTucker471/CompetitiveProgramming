#include <bits/stdc++.h>

using namespace std;

const double EPSILON = 0.0001;

/**
 * Computes n choose k for small result values
 * O(k)
 */
long long nCk(long long n, long long k) {
    double res = 1;
    for (long long i = 1; i <= k; ++i)
        res = res * (n - k + i) / i;
    return (long long)(res + EPSILON);
}

int main() {
    int _;
    cin >> _;

    for (int iter = 1; iter <= _; iter++) {
        int n, m, t;
        cin >> m;
        vector<int> tiles(m);
        for (auto& x : tiles) cin >> x;
        cin >> n >> t;

        // dp[i][j][k] = Number of ways
        // using the first i tiles,
        // to pick j tiles,
        // that sum to k
        vector<vector<vector<long>>> dp(m + 1, vector<vector<long>>(n + 1, vector<long>(t + 1, 0)));

        // Setting the initial points to 1
        for (int i = 0; i <= m; i++) {
            dp[i][0][0] = 1;
        }

        /**
         * Options:
         * We can either add the i-th tile to each concurrent sum,
         * or not add the tile 
         */
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= min(n, i); j++) {
                for (int k = 0; k <= t; k++) {
                    // If we pick the i-th tile
                    if (k >= tiles[i - 1]) {
                        dp[i][j][k] += dp[i - 1][j - 1][k - tiles[i - 1]];
                    }

                    // If we don't pick the i-th tile
                    dp[i][j][k] += dp[i - 1][j][k];
                }
            }
        }

        long long total = nCk(m, n);
        cout << "Game " << iter << " -- " << dp[m][n][t] << " : " << total - dp[m][n][t] << '\n';
    }
}