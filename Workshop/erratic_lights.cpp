#include <bits/stdc++.h>

using namespace std;

int main() {
    // 10^6 possible states

    vector<int> counts(3, 0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        char c; 
        cin >> c;
        if (c == 'r') counts[0]++;
        else if (c == 'g') counts[1]++;
        else counts[2]++;
    }

    vector<vector<vector<double>>> dp(n, vector<vector<double>>(n, vector<double>(n)));

}