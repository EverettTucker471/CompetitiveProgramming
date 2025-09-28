#include<vector>
#include<iostream>
#include<cmath>

using namespace std;

string alph = "abcdefghijklmnopqrstuvwxyz";

void alphabet() {
    string s;
    cin >> s;

    // For string a and b
    // dp[i][j] stores the length of the lcs with the first i character of a
    // and the first j characters of b

    int n = s.size();
    vector<vector<int>> dp(n + 1, vector<int>(27, 0));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j < 27; j++) {
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            if (s[i - 1] == alph[j - 1]) {
                dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 1);
            }
        }
    }

    cout << 26 - dp[n][26] << endl;
}