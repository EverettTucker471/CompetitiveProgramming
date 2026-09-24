#include <bits/stdc++.h>

using namespace std;

int main() {
    long n, dist, price;
    cin >> n;

    unordered_map<long, long> stations;
    while (std::cin >> dist >> price) {
        stations[dist] = stations.count(dist) ? min(price, stations[dist]) : price;
    }

    // dp is cheapest cost for each 
    // (distance from waterloo, gallons of gas) pair
    long T = 200;  // gas tank
    vector<vector<long>> dp(n + 1, vector<long>(T + 1, INT_MAX));

    dp[0][100] = 0;
    for (long i = 1; i <= n; i++) {
        for (long j = T; j >= 0; j--) {
            if (stations.count(i)) {
                for (long x = 1; x <= min(T, j + 1); x++) {
                    dp[i][j] = min(
                        dp[i][j],
                        dp[i - 1][x] + stations[i] * (j - x + 1)
                    );
                }
            } else if (j < T) {
                dp[i][j] = min(
                    dp[i][j],
                    dp[i - 1][j + 1]
                );
            }
        }
    }

    long ans = INT_MAX;
    for (long i = 100; i <= T; i++) ans = min(ans, dp[n][i]);
    ans == INT_MAX ? cout << "Impossible\n" : cout << ans << '\n';
}