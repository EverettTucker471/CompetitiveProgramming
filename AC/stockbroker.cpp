#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<long> prices(n);
    for (auto& x : prices) cin >> x;

    long money = 100;
    long shares = 0;
    for (int i = 0; i < n; i++) {
        if (i < n - 1 && prices[i + 1] >= prices[i]) {
            // Buy
            long new_shares = min(money / prices[i], 100000L - shares);
            money -= new_shares * prices[i];
            shares += new_shares;
        } else {
            // Sell
            money += shares * prices[i];
            shares = 0;
        }
    }

    cout << money << "\n";
}