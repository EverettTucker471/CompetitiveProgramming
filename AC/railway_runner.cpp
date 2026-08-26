#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<vector<char>> a(n, vector<char>(3));
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < 3; j++) a[i][j] = s[j];
    }

    vector<vector<bool>> explored(n, vector<bool>(3, false));

    queue<pair<int, int>> q;
    for (int j = 0; j < 3; j++) {
        if (a[0][j] == '.') {
            q.emplace(0, j);
            explored[0][j] = true;
        }
    }

    while (!q.empty()) {
        pair<int, int> node = q.front();
        q.pop();

        char c = a[node.first][node.second];

        vector<pair<int, int>> possible;
        if (c == '.') {
            // left
            if (node.second > 0 && a[node.first][node.second - 1] == '.') possible.emplace_back(node.first, node.second - 1);
            // right
            if (node.second < 2 && a[node.first][node.second + 1] == '.') possible.emplace_back(node.first, node.second + 1);
            // forward
            if (node.first < n - 1 && a[node.first + 1][node.second] != '*') possible.emplace_back(node.first + 1, node.second);
        } else if (c == '*') {
            // left
            if (node.second > 0 && a[node.first][node.second - 1] == '*') possible.emplace_back(node.first, node.second - 1);
            // right
            if (node.second < 2 && a[node.first][node.second + 1] == '*') possible.emplace_back(node.first, node.second + 1);
            // forward
            if (node.first < n - 1) possible.emplace_back(node.first + 1, node.second);
        } else {
            if (node.first < n - 1) possible.emplace_back(node.first + 1, node.second);
        }

        for (auto x : possible) {
            if (!explored[x.first][x.second]) {
                q.push(x);
                explored[x.first][x.second] = true;
            }
        }
    }

    bool success = false;
    for (int j = 0; j < 3; j++) {
        if (explored[n - 1][j]) success = true;
    }

    cout << (success ? "YES" : "NO") << endl;
}