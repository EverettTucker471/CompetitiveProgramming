#include <bits/stdc++.h>

using namespace std;

bool compare(pair<int, int> a, pair<int, int> b) {
    if (a.second == b.second) {
        return a.first < b.first;
    }
    return a.second < b.second;
}

int main() {
    int n, t, k;
    cin >> n >> t >> k;

    map<int, int> map;  // Map of start times to end times
    for (int i = 0; i < n; i++) {
        int s, e;
        cin >> s >> e;
        if (map.count(s) > 0) {
            map[s] = min(e, map[s]);
        } else {
            map[s] = e;
        }
    }

    vector<pair<int, int>> times;
    for (auto x : map) {
        times.emplace_back(x.first, x.second);
    }
    n = times.size();
    sort(times.begin(), times.end(), compare);  // Sorting by end time

    int max_time = t - k;  // t and k don't matter now

    vector<vector<int>> dp(n + 1, vector<int>(3, 0));  // Stores a list of num_intervals, duration, and max_end_time
    for (int i = 1; i < n + 1; i++) {
        // cout << times[i - 1].first << " " << times[i - 1].second << endl;
        for (int j = 0; j < i; j++) {
            int duration = times[i - 1].second - times[i - 1].first;  // Duration of the current meeting
            
            // If the previous is empty - no conflict so just check time
            if (dp[j][0] == 0) {
                if (duration <= max_time) {
                    if (1 > dp[i][0]) {
                        dp[i][0] = 1;
                        dp[i][1] = duration;
                        dp[i][2] = times[i - 1].second;
                    }
                }
            } else if (dp[j][2] <= times[i - 1].first) {
                if (duration + dp[j][1] <= max_time) {
                    if (1 + dp[j][0] > dp[i][0]) {
                        dp[i][0] = dp[j][0] + 1;
                        dp[i][1] = dp[j][1] + duration;
                        dp[i][2] = max(dp[i][2], times[i - 1].second);
                    }
                }
            }
        }
    }

    int ans = 0;
    for (auto x : dp) {
        ans = max(x[0], ans);
    }

    cout << ans << endl;
}