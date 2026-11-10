#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> cash(n), bill(n);
    for (int i = 0; i < n; i++) {
        cin >> cash[i] >> bill[i];
    }
    
    int total_bill = 0;
    int total_cash = 0;
    for (auto x : cash) total_cash += x;
    for (auto x : bill) total_bill += x;

    int rtn = -1;
    for (int i = 0; i < n; i++) {
        if (total_bill - (total_cash - cash[i]) <= bill[i]) {
            rtn = i;
            break;
        }
    }

    if (rtn < 0) {
        cout << "impossible\n";
    } else {
        cout << rtn + 1 << '\n';
    }
}