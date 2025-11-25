#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    vector<vector<char>> cats(n, vector<char>());
    int end = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        string s;
        cin >> s;
        for (char c : s) {
            end |= (int) pow(2, c - 'a');
            cats[i].push_back(c - 'a');
        }
    }    

    vector<int> dp(1024, INT_MAX);
    dp[0] = 0;
    for (auto& x : cats) {
        sort(x.begin(), x.end());
    }

    for (int i = 0; i < n; i++) {
        int val = 0;
        for (char c : cats[i]) {
            val += pow(2, (int) c);
        }
        for (int j = 0; j < 1024; j++) {
            if (dp[j] != INT_MAX) {
                dp[j | val] = min(dp[j | val], dp[j] + a[i]);
            }
        }
    }
    
    cout << dp[end] << '\n';
}