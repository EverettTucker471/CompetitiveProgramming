#include <bits/stdc++.h>

using namespace std;

int main() {
    // I've already done this problem, but doing it again for practice

    /*
    Case 0:
    #
    #
    #

    Case 1:
    #
    ##
    ##

    Case 2:
    ##
    ##
    #

    Case 3:
    ##
    #
    #

    Case 4:
    #
    #
    ##

    */

    vector<vector<long long>> dp(35, vector<long long>(5, 0));
    dp[0][0] = 1;

    for (int i = 0; i < 32; i++) {
        // Case 1:
        dp[i + 1][3] += dp[i][1];

        // Case 2:
        dp[i + 1][4] += dp[i][2];

        // Case 3:
        dp[i][0] += dp[i][3];
        dp[i + 1][1] += dp[i][3];

        // Case 4:
        dp[i][0] += dp[i][4];
        dp[i + 1][2] += dp[i][4];

        // Case 0:
        dp[i + 1][1] += dp[i][0];
        dp[i + 1][2] += dp[i][0];
        dp[i + 2][0] += dp[i][0];
    }

    int n;
    cin >> n;
    
    while (n >= 0) {
        cout << dp[n][0] << endl;
        cin >> n;
    }
}