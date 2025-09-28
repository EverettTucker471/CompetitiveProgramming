#include<vector>
#include<iostream>
#include<unordered_map>
#include<map>
#include<unordered_set>
#include<set>
#include<cmath>
#include<climits>
#include <algorithm>

using namespace std;

const double curve = 2.5 * M_PI;

void c10() {
    int h, w;
    cin >> h >> w;
    char a[h][w];
    for (auto& x : a) {
        for (auto& y : x) {
            cin >> y;
        }
    }

    int m = 2 * h + 1;
    int n = 2 * w + 1;
    // Do half-steps of the grid
    vector<vector<double>> dp(m, vector<double>(n, INT_MAX));
    dp[0][0] = 0;
    for (int j = 1; j < n; j++) {
        dp[0][j] = std::min(dp[0][j], dp[0][j - 1] + 5);
    }
    for (int i = 1; i < m; i++) {
        dp[i][0] = std::min(dp[i][0], dp[i - 1][0] + 5);
    }
    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            // Half-step column
            if (i % 2 == 1 && j % 2 == 0) {
                if (a[i / 2][(j - 1) / 2] == 'O') {
                    dp[i][j] = std::min(dp[i][j], dp[i - 1][j - 1] + curve);
                }
                dp[i][j] = std::min(dp[i][j], dp[i - 1][j] + 5);
            }
            // Half-step Row
            if (i % 2 == 0 && j % 2 == 1) {
                if (a[(i - 1) / 2][j / 2] == 'O') {
                    dp[i][j] = std::min(dp[i][j], dp[i - 1][j - 1] + curve);
                }
                dp[i][j] = std::min(dp[i][j], dp[i][j - 1] + 5);
            }
            // Full step
            if (i % 2 == 0 && j % 2 == 0) {
                dp[i][j] = std::min(dp[i][j], std::min(dp[i - 1][j] + 5, dp[i][j - 1] + 5));
            }
        }
    }
    /*
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%3.2f ", dp[i][j]);
        }
        cout << endl;
    }
    */
    printf("%.8f", dp[m - 1][n - 1]);
    cout << endl;
}