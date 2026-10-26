#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> slices(n);
    for (auto& x : slices) cin >> x;
    int odd_cnt = 0;
    for (auto& x : slices) odd_cnt += x % 2;

    // For one pizza, you win if there's an even number
    bool win = false;
    if (n == 1) {
        win = odd_cnt == 0;
    } else if (n == 2) {
        win = (odd_cnt == 1 || odd_cnt == 2);
    } else {
        win = (odd_cnt == 0 || odd_cnt == 1 || odd_cnt == 2);
    }
    
    cout << (win ? "Ja\n" : "Nej\n");
}