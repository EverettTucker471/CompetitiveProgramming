#include<vector>
#include<iostream>
#include<unordered_map>
#include<map>
#include<unordered_set>
#include<set>
#include<cmath>
#include <algorithm>

using namespace std;

/*
void volume_amplification() {
    int _;
    cin >> _;

    while (_--) {
        int n, y;
        cin >> n >> y;
        int a[n];
        for (auto& x: a) cin >> x;

        vector<bool> dp(y + 1, false);
        dp[1] = true;
        // dp[i] stores if an amplification of i is reachable
        for (int i = 0; i < n; i++) {
            int index = y / a[i];
            while (index >= 0) {
                dp[index] = dp[index] || dp[index]
            }
            for (int j = y; j >= 0; j--) {
                if (j % a[i] == 0 && j / a[i] >= 0) {
                    dp[j] = dp[j] || dp[j / a[i]];
                }
            }
        }

        for (int i = y; i >= 0; i--) {
            if (dp[i]) {
                cout << i << endl;
                break;
            }
        }
    }
}
 */

void beta() {
    int _;
    cin >> _;

    while (_--) {
        int n, y;
        cin >> n >> y;
        int a[n];
        for (auto &x: a) {
            cin >> x;
        }

        std::set<int> set;
        set.insert(1);

        for (int k : a) {
            std::set<int> copy(set.begin(), set.end());
            for (int l : set) {
                int res = k * l;
                if (res <= y) {
                    copy.insert(res);
                }
            }
            set = copy;
        }

        int rtn = 1;
        for (int z : set) {
            if (z <= y) rtn = max(rtn, z);
        }

        cout << rtn << endl;
    }
}