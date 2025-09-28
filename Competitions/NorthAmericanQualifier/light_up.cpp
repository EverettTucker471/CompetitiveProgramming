#include <iostream>
#include <vector>
#include <climits>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <cmath>

using namespace std;

void light_up() {
    int n;
    cin >> n;
    vector<vector<char>> grid(n, vector<char>(n));

    vector<pair<int, int>> lightbulbs;
    int empty_count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            char x;
            cin >> x;
            if (x == '?') {
                lightbulbs.emplace_back(i, j);
            }
            if (x == '.') {empty_count++;}

            grid[i][j] = x;
        }
    }

    // Exploring empty spaces
    unordered_set<int> empty_spaces;
    for (auto lightbulb : lightbulbs) {
        auto temp = lightbulb;

        // Up
        temp.first--;
        while (temp.first >= 0) {
            if (grid[temp.first][temp.second] == '.') {
                empty_spaces.insert(temp.first * n + temp.second);
            } else if (grid[temp.first][temp.second] == '?') {
                cout << 0;
                return;
            } else {
                break;
            }
            temp.first--;
        }

        // Down
        temp = lightbulb;
        temp.first++;
        while (temp.first < n) {
            if (grid[temp.first][temp.second] == '.') {
                empty_spaces.insert(temp.first * n + temp.second);
            } else if (grid[temp.first][temp.second] == '?') {
                cout << 0;
                return;
            } else {
                break;
            }
            temp.first++;
        }

        // Left
        temp = lightbulb;
        temp.second--;
        while (temp.second >= 0) {
            if (grid[temp.first][temp.second] == '.') {
                empty_spaces.insert(temp.first * n + temp.second);
            } else if (grid[temp.first][temp.second] == '?') {
                cout << 0;
                return;
            } else {
                break;
            }
            temp.second--;
        }

        // Right
        temp = lightbulb;
        temp.second++;
        while (temp.second < n) {
            if (grid[temp.first][temp.second] == '.') {
                empty_spaces.insert(temp.first * n + temp.second);
            } else if (grid[temp.first][temp.second] == '?') {
                cout << 0;
                return;
            } else {
                break;
            }
            temp.second++;
        }
    }

    // Checking Blocks
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] != '.' && grid[i][j] != 'X' && grid[i][j] != '?') {
                int count = 0;

                // Up
                if (i < n - 1 && grid[i + 1][j] == '?') {count++;}
                // Down
                if (i > 0 && grid[i - 1][j] == '?') {count++;}
                // Left
                if (j > 0 && grid[i][j - 1] == '?') {count++;}
                // Right
                if (j < n - 1 && grid[i][j + 1] == '?') {count++;}

                if (count != grid[i][j] - '0') {cout << 0; return;}
            }
        }
    }

    cout << (empty_count == empty_spaces.size() ? 1 : 0);
}