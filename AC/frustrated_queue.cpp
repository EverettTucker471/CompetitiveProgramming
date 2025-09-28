#include <iostream>
#include <vector>

using namespace std;

void frustrated_queue() {
    string s;

    while (cin >> s) {
        int n = s.size();
        vector<vector<int>> dp(n + 1, vector<int>(n, 0));

        // dp[i][j] is the number of ways at position i with j open parentheses
        int mod = 1000000;
        dp[0][0] = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < n; j++) {
                if (s[i - 1] == '(' || s[i - 1] == '.') {
                    if (j < n - 1) {dp[i][j + 1] = (dp[i][j + 1] + dp[i - 1][j]) % mod;}
                }
                if (s[i - 1] == ')' || s[i - 1] == '.') {
                    if (j > 0) {dp[i][j - 1] = (dp[i][j - 1] + dp[i - 1][j]) % mod;}
                }
            }
        }

        cout << dp[n][0] << endl;
    }
}