#include<vector>
#include<iostream>
#include<unordered_map>
#include<map>
#include<unordered_set>
#include<set>
#include<cmath>
#include <algorithm>
#include <climits>

using namespace std;

// Accepted!
void a20() {
    // Hashmap problem --> Nope, much harder
    int _;
    cin >> _;

    while (_--) {
        int n;
        cin >> n;
        int a[n];
        for (auto& x : a) cin >> x;
        vector<vector<int>> occur(n + 1, vector<int>());
        vector<int> dp(n + 1, 0);  // Stores the value of the longest neat subsequence

        for (int i = 0; i < n; i++) {
            occur[a[i]].push_back(i);

            int k = (int) occur[a[i]].size();
            if (k >= a[i]) {
                dp[i + 1] = max(dp[i], dp[occur[a[i]][k - a[i]]] + a[i]);
            } else {
                dp[i + 1] = max(dp[i + 1], dp[i]);
            }
        }

        cout << dp[n] << endl;
    }
}