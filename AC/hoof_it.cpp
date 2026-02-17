#include <bits/stdc++.h>

using namespace std;

/**
 * This problem is #10 from AoC 2024
 */


const vector<int> dx = {0, 1, 0, -1};
const vector<int> dy = {1, 0, -1, 0};

vector<pair<int, int>> valid(pair<int, int> node, const vector<string>& grid, const vector<vector<bool>>& explored, int m, int n) {
    vector<pair<int, int>> rtn;

    for (int i = 0; i < 4; i++) {
        pair<int, int> temp = {node.first + dx[i], node.second + dy[i]};
        if (temp.first >= 0 && temp.first < m && temp.second >= 0 && temp.second < n) {
            if (grid[temp.first][temp.second] == grid[node.first][node.second] + 1) {
                rtn.push_back(temp);
            }
        }
    }

    return rtn;
}

void solve1() {
    vector<string> grid;

    string s;
    while (getline(cin, s) && !s.empty()) {
        grid.push_back(s);
    }

    vector<pair<int, int>> starts;
    int m = grid.size();
    int n = grid[0].size();

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == '0') {
                starts.emplace_back(i, j);
            }
        }
    }

    int rtn = 0;
    for (pair<int, int> s : starts) {
        queue<pair<int, int>> q;
        vector<vector<bool>> explored(m, vector<bool>(n, false));
        explored[s.first][s.second] = true;
        q.push(s);

        while (!q.empty()) {
            auto node = q.front();
            q.pop();

            for (pair<int, int> v : valid(node, grid, explored, n, m)) {
                if (grid[v.first][v.second] == '9') {
                    rtn++;
                } else {
                    q.push(v);
                }
                explored[v.first][v.second] = true;
            }
        }
    }

    cout << rtn << endl;
}

void solve2() {
    vector<string> grid;

    string s;
    while (getline(cin, s) && !s.empty()) {
        grid.push_back(s);
    }

    vector<pair<int, int>> starts;
    int m = grid.size();
    int n = grid[0].size();

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == '0') {
                starts.emplace_back(i, j);
            }
        }
    }

    int rtn = 0;
    for (pair<int, int> s : starts) {
        queue<pair<int, int>> q;
        vector<vector<bool>> explored(m, vector<bool>(n, false));
        vector<vector<int>> count(m, vector<int>(n, 0));
        count[s.first][s.second] = 1;
        explored[s.first][s.second] = true;
        q.push(s);

        while (!q.empty()) {
            auto node = q.front();
            q.pop();

            for (pair<int, int> v : valid(node, grid, explored, n, m)) {
                count[v.first][v.second] += count[node.first][node.second];
                if (!explored[v.first][v.second]) {
                    q.push(v);
                    explored[v.first][v.second] = true;
                }
            }
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '9') {
                    rtn += count[i][j];
                }
            }
        }
    }

    cout << rtn << endl;
}

int main() {
    solve2();
}