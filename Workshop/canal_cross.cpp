#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<vector<pair<int, int>>> adj;
unordered_map<int, int> bridge1, bridge2;

int main() {
    cin >> n;
    adj.assign(n, vector<pair<int, int>>());

    for (int i = 0; i < n - 1; i++) {
        int a, b, w;
        a--;
        b--;
        adj[a].push_back({b, w});
        adj[b].push_back({a, w});
    }

    cin >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        bridge1[a] = b;
        bridge2[b] = a;
    }
    
    pair<int, int> start = *bridge1.begin();
    
    priority_queue<pair<double, int>> pq;
    pq.push({start.second, 0});

    while (!pq.empty()) {
        auto p = pq.top();
        pq.pop();
        double dist = p.first;
        int node = p.second;

        for (auto v : adj[node]) {
            
        }
    }
}