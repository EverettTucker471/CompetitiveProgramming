#include <bits/stdc++.h>

using namespace std;

int main() {
    int slow_speed = 1000;
    int fast_speed, swap;
    cin >> fast_speed >> swap;

    set<char> left = {
        'q', 'w', 'e', 'r', 't', 
        'a', 's', 'd', 'f', 'g', 
        'z', 'x', 'c', 'v', 'b'
    };

    string s;
    cin.ignore();
    getline(cin, s);
    int n = s.size();
    vector<vector<int>> dp(n + 1, vector<int>(2, INT_MAX));
    dp[0][0] = 0;
    dp[0][1] = 0;

    for (int i = 1; i <= n; i++) {
        char c = s[i - 1];

        if (c == ' ') {
            // Fast regardless - never optimal to swap here
            dp[i][0] = min(dp[i][0], dp[i - 1][0] + fast_speed);
            dp[i][1] = min(dp[i][1], dp[i - 1][1] + fast_speed);
        } else if (left.count(c)) {
            // Typing with left is preferred
            dp[i][0] = min(dp[i][0], dp[i - 1][0] + fast_speed);
            dp[i][1] = min(dp[i][1], min(dp[i - 1][1] + slow_speed, dp[i - 1][0] + swap + fast_speed));
        } else {
            dp[i][0] = min(dp[i][0], min(dp[i - 1][0] + slow_speed, dp[i - 1][1] + swap + fast_speed));
            dp[i][1] = min(dp[i][1], dp[i - 1][1] + fast_speed);
        }
    }

    cout << min(dp[n][0], dp[n][1]) << "\n";
}