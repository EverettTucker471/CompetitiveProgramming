#include <bits/stdc++.h>

using namespace std;

int main() {
    int _;
    cin >> _;

    while (_--) {
        int n;
        cin >> n;
        vector<int> s(n);
        vector<double> p(n);
        for (int i = 0; i < n; i++) {
            int percent;
            cin >> s[i] >> percent;
            p[i] = (double) percent / 100.0;
        }

        // dp[i][j] = highest prob. using i parties to get to j seats 
        vector<vector<double>> dp(n + 1, vector<double>(151, 0.0));
        dp[0][0] = 1.0;

        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= 150; j++) {
                // If we use it
                if (j - s[i - 1] >= 0) {
                    dp[i][j] = max(dp[i][j], dp[i - 1][j - s[i - 1]] * p[i - 1]);
                }

                // If we don't use it
                dp[i][j] = max(dp[i][j], dp[i - 1][j]);
            }
        }

        double rtn = 0.0;
        for (int j = 76; j <= 150; j++) rtn = max(rtn, dp[n][j]);
        printf("%.7lf\n", rtn * 100.0);
    }
}