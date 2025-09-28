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

void c6() {
    int _;
    cin >> _;

    while (_--) {
        int n;
        cin >> n;
        vector<vector<bool>> a(2, vector<bool>(n));

        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < n; j++) {
                char c;
                cin >> c;
                a[i][j] = c == 'A';
            }
        }

        for (const auto& x : a) {
            for (auto y : x) {
                cout << y;
            }
            cout << endl;
        }

        vector<vector<int>> dp(n + 2, vector<int>(7, 0));

        for (int i = 2; i < n + 2; i++) {
            // Top Triple
            if (i < n - 2) {
                dp[i][0] = max(dp[i][0], dp[i - 1][6] + (a[i - 2][0] + a[i - 1][0] + a[i][0] > 1));

                // Bottom Triple
                dp[i][1] = max(dp[i][1], dp[i - 1][6] + (a[i - 2][1] + a[i - 1][1] + a[i][1] > 1));
            }

            if (i < n - 1) {
                // Top double
                dp[i][2] = max(dp[i][2], dp[i - 1][5] + (a[i - 2][0]));
            }
        }

    }
}