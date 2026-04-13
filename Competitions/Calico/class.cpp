#include <bits/stdc++.h>

using namespace std;

int main() {
    int _;
    cin >> _;

    while (_--) {
        int n, m, k;
        cin >> n >> m >> k;

        int k_save = k;

        vector<vector<char>> grid(n, vector<char>(m));
        for (auto& x : grid) {
            for (auto& y : x) {
                cin >> y;
            }
        }

        // Start with a big box, then greedily shrink-wrap it
        pair<int, int> tl = {0, 0};
        pair<int, int> br = {n - 1, m - 1};

        int pts = 0;
        for (auto x : grid) {
            for (auto y : x) {
                pts += y == '-';
            }
        }

        cout << pts << endl;

        // Only care about the maximum dimension, if unequal

        while (pts >= k) {
            // Top, right, bottom, left
            vector<int> side_pts = {0, 0, 0, 0};
            
            // Top
            for (int j = tl.second; j <= br.second; j++) {
                side_pts[0] += grid[tl.first][j] == '-';
            }
            // Right
            for (int i = tl.first; i <= br.first; i++) {
                side_pts[1] += grid[i][br.second] == '-';
            }
            // Bottom
            for (int j = tl.second; j <= br.second; j++) {
                side_pts[2] += grid[br.first][j] == '-';
            }
            // left
            for (int i = tl.first; i <= br.first; i++) {
                side_pts[3] += grid[i][tl.second] == '-';
            }

            int min_pts = INT_MAX;
            int min_pts_idx = 0;
            for (int i = 0; i < 4; i++) {
                if (side_pts[i] < min_pts) {
                    min_pts = side_pts[i];
                    min_pts_idx = i;
                }
            }

            if (pts - min_pts < k) break;
            
            if (min_pts_idx == 0) {
                // Top
                tl = {tl.first + 1, tl.second};
            } else if (min_pts_idx == 1) {
                // Right
                br = {br.first, br.second - 1};
            } else if (min_pts_idx == 2) {
                // Bottom
                br = {br.first - 1, br.second};
            } else {
                tl = {tl.first, tl.second + 1};
            }

            // cout << tl.first << " " << tl.second << endl;
            // cout << br.first << " " << br.second << endl;

            pts -= min_pts;
        }

        int cnt = 0;
        for (int i = tl.first; i <= br.first; i++) {
            for (int j = tl.second; j <= br.second; j++) {
                if (grid[i][j] == '-') {
                    cout << i << " " << j << "\n";
                    cnt++;
                }
                // if (cnt == k_save) exit(0);
            }
        }
    }
}