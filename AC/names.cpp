#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    cin >> s;

    int n = s.size();

    int rtn = INT_MAX;
    for (int i = 0; i < n; i++) {
        // Compute the cost with adding i characters

        int cost = i;
        int left = i;
        int right = n - 1;
        while (left < right) {
            cost += s[left] != s[right];
            left++;
            right--;
        }
        
        rtn = min(rtn, cost);
    }

    cout << rtn << '\n';
}