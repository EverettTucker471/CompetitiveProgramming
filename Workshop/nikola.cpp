#include <bits/stdc++.h>

using namespace std;

void nikola() {
    int n;
    cin >> n;
    vector<int> w(n);
    for (auto& x : w) cin >> x;

    vector<vector<int>> cost(n, vector<int>(n, INT_MAX));
    queue<pair<int, int>> queue;
    queue.push({0, 1});  // Stores space, jump length
    cost[0][0] = w[0];

    while (!queue.empty()) {
        auto node = queue.front();
        queue.pop();

        // Forward
        if (node.first + node.second + 1 < n) {
            if (cost[node.first + node.second + 1][node.second] == INT_MAX) {
                queue.push({node.first + node.second + 1, node.second + 1});
            }
            cost[node.first + node.second + 1][node.second] = min(
                cost[node.first + node.second + 1][node.second], cost[node.first][node.second - 1] + w[node.first + node.second + 1]
            );   
        }

        // Backward
        if (node.first - node.second >= 0) {
            if (cost[node.first - node.second][node.second - 1] == INT_MAX) {
                queue.push({node.first - node.second, node.second});
            }
            cost[node.first - node.second][node.second - 1] = min(
                cost[node.first - node.second][node.second - 1], cost[node.first][node.second - 1] + w[node.first - node.second]
            );
        }
    }

    int rtn = INT_MAX;
    for (int i = 0; i < n; i++) {
        rtn = min(rtn, cost[n - 1][i]);
    }

    cout << rtn << endl;
}

int main() {
    nikola();
    return 0;
}