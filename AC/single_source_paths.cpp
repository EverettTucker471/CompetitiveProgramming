#include <bits/stdc++.h>
#include <queue>

using namespace std;

#define MAX_VAL 1000000000

int main() {
    int n, m, q, s;

    while (cin >> n >> m >> q >> s) {
        if (n == 0) exit(0);

        vector<vector<pair<int, int>>> adj(n);

        for (int i = 0; i < m; i++) {
            int u, v, c;
            cin >> u >> v >> c;

            adj[u].push_back({v, c});
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> dist(n, MAX_VAL);

        dist[s] = 0;
        pq.push({0, s});

        while (!pq.empty()) {
            pair<int, int> x = pq.top();
            pq.pop();

            int cost = x.first;
            int node = x.second;

            if (cost > dist[node]) continue;

            for (pair<int, int> u : adj[node]) {
                if (dist[u.first] > u.second + cost) {
                    dist[u.first] = u.second + cost;
                    pq.push({dist[u.first], u.first});
                }
            }
        }

        for (int i = 0; i < q; i++) {
            int query;
            cin >> query;
            if (dist[query] != MAX_VAL) {
                cout << dist[query] << "\n";
            } else {
                cout << "Impossible\n";
            }
        }
    }
}