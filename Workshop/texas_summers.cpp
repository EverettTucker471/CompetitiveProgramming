#include<vector>
#include<iostream>
#include<cmath>
#include <algorithm>
#include <queue>
#include <climits>

using namespace std;

void texas_summers() {
    int n;
    cin >> n;

    long int pts[n + 2][2];
    for (auto x : pts) {
        cin >> x[0] >> x[1];
    }

    vector<int> prev(n + 2, -1);
    vector<int> dist(n + 2, INT_MAX);
    vector<bool> visited(n + 2, false);

    // (Distance, index) pairs
    dist[n] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, std::greater<>> pq;
    pq.emplace(0, n);
    while (!pq.empty()) {
        pair<int, int> node = pq.top();
        pq.pop();
        visited[node.second] = true;
    
        // First is distance, second is index
        for (int j = 0; j < n + 2; j++) {
            if (!visited[j] && j != node.second) {
                int dx = pts[node.second][0] - pts[j][0];
                int dy = pts[node.second][1] - pts[j][1];
                int new_dist = dx * dx + dy * dy;
                if (new_dist + dist[node.second] < dist[j]) {
                    prev[j] = node.second;
                    dist[j] = new_dist + node.first;
                    pq.emplace(dist[j], j);
                }
            }
        }
    }

    int index = n + 1;
    vector<int> path;
    while (prev[index] >= 0) {
        path.push_back(index);
        index = prev[index];
    }

    reverse(path.begin(), path.end());
    if (path.size() <= 2) {
        cout << '-' << endl;
    } else {
        for (int i = 0; i < path.size() - 1; i++) {
            cout << path[i] << endl;
        }
    }
}