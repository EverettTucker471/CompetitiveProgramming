#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, c;
    cin >> n >> c;

    int a[n];
    for (auto& x : a) cin >> x;

    int rtn = 0;
    for (int i = 0; i < n; i++) {
        // i is our starting position, we maximize the eating value for each start greedily
        int amt = 0;
        int count = 0;
        for (int j = i; j < n; j++) {
            if (amt + a[j] <= c) {
                amt += a[j];
                count++;
            }
        }
        rtn = max(rtn, count);
    }

    cout << rtn << "\n";
}