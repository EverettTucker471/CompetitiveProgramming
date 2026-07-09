#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> adj = {
    {0},
    {1, 2, 3, 4, 5, 6, 7, 8, 9, 0},
    {2, 5, 8, 0, 3, 6, 9},
    {3, 6, 9},
    {4, 5, 6, 7, 8, 9, 0},
    {5, 6, 8, 9, 0},
    {6, 9},
    {7, 8, 9, 0},
    {8, 0, 9},
    {9}
};

vector<int> pos = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

int main() {
    for (int i = 0; i < 2; i++) {
        int n = pos.size();
        for (int j = 0; j < n; j++) {
            for (int v : adj[pos[j] % 10]) {
                pos.push_back(pos[j] * 10 + v);
            }
        }
    }

    int _;
    cin >> _;
    
    while (_--) {
        int k;
        cin >> k;

        int dist = INT_MAX;
        int ans = 0;
        for (int num : pos) {
            int d = abs(num - k);
            if (d < dist) {
                dist = d;
                ans = num;
            }
        }

        cout << ans << "\n";
    } 
}