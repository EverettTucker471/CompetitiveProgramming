#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (auto& x : a) {
        cin >> x;
        x--;
    }

    long long rtn = 0;

    // Stores number of signals using up to port n
    map<int, int> dp;
    dp[-1] = 0;
    dp[0] = 0;
    int best = 0;
    for (int i = 0; i < n; i++) {
        dp[a[i]] = max(best, dp.upper_bound(a[i])->second + 1);
        best = max(best, dp[a[i]]);
    }

    cout << best << "\n";
}