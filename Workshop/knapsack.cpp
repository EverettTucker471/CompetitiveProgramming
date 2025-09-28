#include <iostream>
#include <vector>

using namespace std;

void knapsack() {
    int W, n;
    while (cin >> W) {
        cin >> n;
        int w[n];
        int v[n];
        for (int i = 0; i < n; i++) {
            cin >> v[i];
            cin >> w[i];
        }

        // dp[i][j] stores the maximum achievable value with capacity i and the first j elements
        vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));
        vector<vector<int>> parent(n + 1, vector<int>(W + 1, 0));
        for (int i = 1; i <= n; i++) {
            for (int j = W; j >= w[i - 1]; j--) {
                if (dp[i - 1][j] > dp[i - 1][j - w[i - 1]] + v[i - 1]) {
                    parent[i][j] = -1;
                } else {
                    parent[i][j] = i - 1;
                }
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i - 1]] + v[i - 1]);
            }
        }

        vector<int> res;
        int i = n;
        int j = W;
        while (i > 0 && j > 0) {
            if (dp[i][j] == 0) {break;}
            if (parent[i][j] >= 0) {
                res.push_back(parent[i][j]);
                j -= w[parent[i][j]];
            }
            i--;
        }

        int n = res.size();
        cout << n << endl;
        for (int i = n - 1; i >= 0; i--) {
            cout << res[i] << " ";
        }
        cout << endl;
    }
}