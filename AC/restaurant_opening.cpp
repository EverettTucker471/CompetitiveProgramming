#include<vector>
#include<iostream>
#include<unordered_map>
#include<map>
#include<unordered_set>
#include<set>
#include<cmath>
#include <algorithm>
#include <climits>

using namespace std;

void r_opening() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    vector<int> row_sums(n, 0);
    vector<int> col_sums(m, 0);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            row_sums[i] += grid[i][j];
        }
    }

    for (int j = 0; j < m; j++) {
        for (int i = 0; i < n; i++) {
            col_sums[j] += grid[i][j];
        }
    }

    // Brute force in x and y
    int rtn = 0;
    int min_cost_x = INT_MAX;
    for (int x_index = 0; x_index < n; x_index++) {
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += row_sums[i] * abs(i - x_index);
        }
        min_cost_x = std::min(min_cost_x, sum);
    }

    int min_cost_y = INT_MAX;
    for (int y_index = 0; y_index < m; y_index++) {
        int sum = 0;
        for (int j = 0; j < m; j++) {
            sum += col_sums[j] * abs(j - y_index);
        }
        min_cost_y = std::min(min_cost_y, sum);
    }

    cout << min_cost_x + min_cost_y << endl;
}