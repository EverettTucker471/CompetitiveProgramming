#include <bits/stdc++.h>
#include <queue>

using namespace std;

int main() {
    // Basic dijkstras

    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, int>>> adj(n);

    for (int i = 0; i < m; i++) {
        int u, v, c;
        cin >> u >> v >> c;
        u--;
        v--;

        adj[u].push_back({v, c});
        adj[v].push_back({u, c});
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> dist(n, INT_MAX);

    dist[0] = 0;
    pq.push({0, 0});

    while (!pq.empty()) {
        pair<int, int> x = pq.top();
        pq.pop();

        int cost = x.first;
        int node = x.second;

        if (cost != dist[node]) continue;

        for (pair<int, int> u : adj[node]) {
            if (dist[u.first] > u.second + cost) {
                dist[u.first] = u.second + cost;
                pq.push({dist[u.first], u.first});
            }
        }
    }

    cout << dist[n - 1] << "\n";
}