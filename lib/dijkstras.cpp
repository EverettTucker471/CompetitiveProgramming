#include <bits/stdc++.h>

using namespace std;

/**
 * @param n number of vertices
 * @param s start vertex
 * @param e end vertex
 * @param adj adjacency list ordered by vertex, cost
 */
double dijkstras(int n, int s, int e, vector<vector<pair<int, double>>> adj) {
    priority_queue<pair<double, int>, vector<pair<double, int>>, greater<pair<double, int>>> pq;
    vector<double> dist(n, DBL_MAX);
    vector<int> parent(n);

    dist[s] = 0;
    pq.emplace(0, s);

    while (!pq.empty()) {
        auto x = pq.top();
        pq.pop();

        double cost = x.first;
        int node = x.second;

        // If the cost is stale
        if (cost > dist[node]) continue;

        for (auto u : adj[node]) {
            if (dist[u.first] > u.second + cost) {
                dist[u.first] = u.second + cost;
                parent[u.first] = node;
                pq.push({dist[u.first], u.first});
            }
        }
    }

    return dist[e];
}