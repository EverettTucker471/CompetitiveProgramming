#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<bool>> grid(n, vector<bool>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char a;
            cin >> a;
            grid[i][j] = (a == 'X');
        }
    }

    // Find the size of the largest square in the grid
    
    // Side length of largest square with bottom right corner at (i, j)
    vector<vector<int>> dp(n, vector<int>(m, 0));

    for (int i = 0; i < n; i++) dp[i][0] = grid[i][0];
    for (int j = 0; j < m; j++) dp[0][j] = grid[0][j];

    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            if (grid[i][j]) {
                dp[i][j] = max(
                    dp[i][j],
                    min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1
                );
            }
        }
    }

    int biggest_square = 0;
    vector<pair<int, int>> locs;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (dp[i][j] > biggest_square) {
                biggest_square = dp[i][j];
                locs.clear();
                locs.emplace_back(i, j);
            }
        }
    }

    // Going through all the locations with biggest squares
    for (auto x : locs) {
        cout << x.first << " " << x.second << '\n';
    }

    cout << (biggest_square + 1) / 2 << '\n';

    // for (auto x : dp) {
    //     for (auto y : x) {
    //         cout << y << " ";
    //     }
    //     cout << endl;
    // }
}