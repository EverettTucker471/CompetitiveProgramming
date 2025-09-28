#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int points(int time) {
    time = std::abs(time);
    if (time <= 15) {
        return 7;
    } else if (time <= 23) {
        return 6;
    } else if (time <= 43) {
        return 4;
    } else if (time <= 102) {
        return 2;
    } else {
        return 0;
    }
}

int compute(const int larger[], int smaller[], int l, int s) {
    // dp[i][j] = highest points when pairing the
    // last i elements of smaller with the last j indices of larger
    vector<vector<int>> dp(s + 1, vector<int>(l + 1, 0));

    for (int i = 1; i <= s; i++) {
        for (int j = 1; j <= l; j++) {
            dp[i][j] = std::max(std::max(dp[i][j], std::max(dp[i][j - 1], dp[i - 1][j])), points(smaller[i - 1] - larger[j - 1]) + dp[i - 1][j - 1]);
        }
    }

    return dp[s][l];
}

void rhythm_flow() {
    int n, m;
    cin >> n >> m;

    int expected[n];
    for (auto& x : expected) {cin >> x;}
    int actual[m];
    for (auto& x : actual) {cin >> x;}

    if (m < n) {
        cout << compute(expected, actual, n, m);
    } else {
        cout << compute(actual, expected, m, n);
    }
}
