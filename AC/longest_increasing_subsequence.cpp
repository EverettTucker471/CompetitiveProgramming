#include<vector>
#include<iostream>
#include<unordered_map>
#include<map>
#include<unordered_set>
#include<set>
#include<cmath>
#include <algorithm>

using namespace std;

void lis() {
    /*
     * We keep track of the longest increasing subsequence up to index i
     * For each number that it ends with
     */
    int n;
    cin >> n;
    while (n) {
        int arr[n];
        set<int> ordered_set;
        for (auto& x : arr) {
            cin >> x;
            ordered_set.insert(x);
        }

        vector<int> sorted(ordered_set.begin(), ordered_set.end());
        int m = sorted.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                if (sorted[j - 1] == arr[i - 1]) {
                    dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 1);
                }
            }
        }

        // Now we need to reconstruct the lcs
        vector<int> lcs;
        int i = n;
        int j = m;
        while (i > 0 && j > 0) {
            if (sorted[j - 1] == arr[i - 1]) {
                lcs.push_back(sorted[j - 1]);
                i--;
                j--;
            } else if (dp[i][j - 1] == dp[i][j]) {
                j--;
            } else {
                i--;
            }
        }

        cout << dp[n][m] << " ";
        for (int z = lcs.size() - 1; z >= 0; z--) {
            cout << lcs[z] << " ";
        }
        cout << endl;
        cin >> n;
    }
}