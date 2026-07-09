#include <bits/stdc++.h>

using namespace std;

double dist(pair<double, double> a, pair<double, double> b) {
    return sqrt((a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second));
}

int main() {
    pair<double, double> start, end;
    cin >> start.first >> start.second;
    cin >> end.first >> end.second;

    int n;
    cin >> n;
    vector<pair<double, double>> cannons(n);

    for (auto& x : cannons) {
        cin >> x.first >> x.second;
    }
    
    // Each cannon, and the start and end are nodes
    vector<vector<pair<int, double>>> adj(n + 2);

    // Start to cannons
    for (int i = 1; i < n + 1; i++) {
        adj[0].push_back({i, dist(start, cannons[i - 1]) / 5});
    }

    // Cannons to cannons
    for (int i = 1; i < n + 1; i++) {
        for (int j = 1; j < n + 1; j++) {
            if (i != j) {
                double cdist = abs(dist(cannons[i - 1], cannons[j - 1]) - 50) / 5 + 2;
                double rdist = dist(cannons[i - 1], cannons[j - 1]) / 5;
                adj[i].push_back({j, min(cdist, rdist)});
            }
        }
    }

    // Cannons to end
    for (int i = 1; i < n + 1; i++) {
        double cdist = abs(dist(cannons[i - 1], end) - 50) / 5 + 2;
        double rdist = dist(cannons[i - 1], end) / 5;
        adj[i].push_back({n + 1, min(cdist, rdist)});
    }

    // Start to end
    adj[0].push_back({n + 1, dist(start, end) / 5});

    priority_queue<pair<double, int>, vector<pair<double, int>>, greater<pair<double, int>>> pq;
    vector<double> dist(n + 2, DBL_MAX);

    dist[0] = 0;
    pq.emplace(0, 0);

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
                pq.push({dist[u.first], u.first});
            }
        }
    }

    printf("%.8lf\n", dist[n + 1]);
}