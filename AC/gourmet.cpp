#include<vector>
#include<iostream>
#include<cmath>

using namespace std;

void gourmet() {
    int m, n;
    cin >> m >> n;

    vector<int> times(n);
    for (auto& x : times) {cin >> x;}
    vector<int> dp(m + 1, 0);

    // He has to be eating constantly
    dp[0] = 1;
    for (int i = 0; i <= m; i++) {
        if (dp[i]) {
            for (int time: times) {
                if (i + time <= m) {
                    dp[i + time] += dp[i];
                }
            }
        }
    }

    cout << dp[m] << endl;
}