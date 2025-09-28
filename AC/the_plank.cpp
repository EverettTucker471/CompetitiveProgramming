#include<vector>
#include<iostream>
#include<cmath>

using namespace std;

void the_plank() {
    int n;
    cin >> n;

    vector<int> dp(n + 1, 0);
    dp[0] = 1;

    for (int i = 1; i <= n; i++) {
        for (int k = 1; k <= 3; k++) {
            if (i - k >= 0) {
                dp[i] += dp[i - k];
            }
        }
    }

    cout << dp[n] << endl;
}