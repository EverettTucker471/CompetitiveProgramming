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

void e15() {
    int d;
    cin >> d;
    vector<int> p(d);
    for (auto& x : p) cin >> x;

    // Stores the amount of money at each day
    vector<long long int> dp(d);
    dp[0] = 100;

    for (int i = 1; i < d; i++) {
        for (int j = 0; j < i; j++) {
            int stock_bought = dp[j] / p[j];
        }
    }

    for (auto x : dp) {
        cout << x << " ";
    }
}