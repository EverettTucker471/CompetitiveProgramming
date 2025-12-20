#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    int types[n];
    for (auto& x : types) cin >> x;

    vector<vector<int>> adj(n, vector<int>());

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u - 1].push_back(v - 1);
        adj[v - 1].push_back(u - 1);
    }

    vector<int> dist(n, INT_MAX);

    queue<int> q;
    vector<bool> explored(n, false);

    q.push(0);
    explored[0] = true;
    dist[0] = 0;

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        explored[node] = true;

        for (int v : adj[node]) {
            dist[v] = min(dist[v], dist[node] + 1);
            if (!explored[v]) {
                q.push(v);
            }
        }
    }

    vector<int> product_dist(k, 0);
    for (int i = 0; i < n; i++) {
        product_dist[types[i] - 1] = max(product_dist[types[i] - 1], dist[i]);
    }

    for (auto x : product_dist) {
        cout << x << " ";
    }
}