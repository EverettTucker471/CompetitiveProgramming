#include<vector>
#include<iostream>
#include<cmath>

using namespace std;

void compositions() {
    int _;
    cin >> _;

    while (_--) {
        int K, n, m, k;
        cin >> K >> n >> m >> k;

        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        for (int i = 0; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (j % k != m) {
                    if (i + j <= n) {
                        dp[i + j] += dp[i];
                    }
                }
            }
        }

        cout << K << " " << dp[n] << endl;
    }
}