#include<iostream>
#include<climits>
#include <vector>

using namespace std;

void tri_tiling() {
    vector<vector<long long int>> dp(33, vector<long long int>(7, 0));
    // Stores amount ending at index i
    dp[0][0] = 1;

    for (int i = 0; i < 31; i++) {
        // Case 1
        dp[i][0] += dp[i][1];
        dp[i + 1][4] += dp[i][1];

        // Case 2
        dp[i + 1][5] += dp[i][5];

        // Case 3
        dp[i + 1][6] += dp[i][3];
        dp[i][0] += dp[i][3];

        // Case 4
        dp[i + 1][1] += dp[i][4];

        // Case 5
        dp[i + 1][2] += dp[i][5];

        // Case 6
        dp[i + 1][3] += dp[i][6];

        // Case 0
        dp[i + 2][0] += dp[i][0];
        dp[i + 1][4] += dp[i][0];
        dp[i + 1][6] += dp[i][0];
    }

    vector<int> queries;
    while (true) {
        int n;
        cin >> n;
        if (n < 0) {break;}
        queries.push_back(n);
    }

    for (auto x : queries) {
        cout << dp[x][0] << endl;
    }
}
