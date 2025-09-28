#include<vector>
#include<iostream>
#include<unordered_map>
#include<map>
#include<unordered_set>
#include<set>
#include<cmath>
#include <algorithm>

using namespace std;

void okvir() {
    int m, n, u, l, r, d;
    cin >> m >> n >> u >> l >> r >> d;

    vector<string> words(m);
    for (auto& a : words) {
        cin >> a;
    }

    vector<vector<char>> grid(m + u + d, vector<char>(n + l + r));

    for (int i = 0; i < m + u + d; i++) {
        for (int j = 0; j < n + l + r; j++) {
            grid[i][j] = ((i + j) % 2 ? '.' : '#');
        }
    }

    for (int i = u; i < u + m; i++) {
        for (int j = 0; j < n; j++) {
            grid[i][j + l] = words[i - u][j];
        }
    }

    for (const auto& z : grid) {
        for (auto y : z) {
            cout << y;
        }
        cout << endl;
    }
}