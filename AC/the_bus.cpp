#include <bits/stdc++.h>

using namespace std;

int main() {
    // This is knapsack - but like way easier
    int k;
    cin >> k;

    int rtn = 0;
    
    // Take 500s greedily first
    rtn += k / 500;
    k %= 500;

    // Cases
    if (k > 400) {
        // One 500
        rtn += 1;
    } else if (k > 300) {
        // Two 200s
        rtn += 2;
    } else if (k > 200) {
        // One 200, one 100
        rtn += 2;
    } else if (k > 100) {
        // One 200
        rtn += 1;
    } else if (k > 0) {
        // One 100
        rtn += 1;
    }
    
    cout << rtn << '\n';
}