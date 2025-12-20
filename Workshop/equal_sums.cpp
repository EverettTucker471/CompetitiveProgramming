#include <bits/stdc++.h>

using namespace std;

#define MAX_SUM 2000000

int main() {
    int _;
    cin >> _;

    for (int c = 0; c < _; c++) {
        int n;
        cin >> n;

        int a[n];
        for (auto& x : a) cin >> x;

        vector<vector<int>> dp(n + 1, vector<int>(MAX_SUM, 0));
        dp[0][0] = 1;

        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < MAX_SUM; j++) {
                dp[i][j] += dp[i - 1][j];  // Not adding
                if (dp[i - 1][j] > 0) {
                    dp[i][j + a[i - 1]] += dp[i - 1][j];  // Adding
                }
            }
        }

        int index = -1;
        for (int j = 0; j < MAX_SUM; j++) {
            if (dp[n][j] > 1) {
                index = j;
                break;
            }
        }

        // Backtracking
        vector<int> rtn;
        for (int i = n; i > 0; i--) {
            if (dp[i - 1][index] <= dp[i][index]) {
                rtn.push_back(a[i - 1]);
            }
        }

        for (auto x : rtn) {
            cout << x << " ";
        }
        cout << '\n';
    }

    return 0;
}