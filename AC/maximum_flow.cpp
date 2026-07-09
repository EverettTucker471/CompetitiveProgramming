#include <bits/stdc++.h>

using namespace std;

int n;
vector<vector<int>> adj;  // Adjacency list
vector<vector<long>> cap;  

/**
 * BFS helper function for max flow
 * @param s the index of the source vertex
 * @param t the index of the sink vertex
 * @param parent an array of parent indices
 * @return 
 */
int bfs(int s, int t, vector<int>& parent) {
    fill(parent.begin(), parent.end(), -1);
    parent[s] = -2;
    queue<pair<int, long>> q;
    q.push({s, LONG_MAX});

    while (!q.empty()) {
        int cur = q.front().first;
        long flow = q.front().second;
        q.pop();

        for (int next : adj[cur]) {
            if (parent[next] == -1 && cap[cur][next]) {
                parent[next] = cur;
                long new_flow = min(flow, cap[cur][next]);
                if (next == t) return new_flow;
                q.push({next, new_flow});
            }
        }
    }

    return 0;
}

/**
 * Implements Edmond-Karp to solve the max flow problem
 * Runs in O(VE^2)
 * @param s the index of the source vertex
 * @param t the index of the sink vertex
 * @return the maximum flow achievable through the graph
 */
int max_flow(int s, int t) {
    long flow = 0;
    vector<int> parent(n);
    long new_flow;

    while (new_flow = bfs(s, t, parent)) {
        flow += new_flow;
        int cur = t;
        while (cur != s) {
            int prev = parent[cur];
            cap[prev][cur] -= new_flow;
            cap[cur][prev] += new_flow;
            cur = prev;
        }
    }

    return flow;
}


int main() {
    int m, s, t;
    cin >> n >> m >> s >> t;

    // (Vertex, capacity) pairs
    adj.assign(n, vector<int>());
    cap.assign(n, vector<long>(n, 0));
    for (int i = 0; i < m; i++) {
        int u, v, c;
        cin >> u >> v >> c;
        
        adj[u].push_back(v);
        adj[v].push_back(u);  // Adding a back-edge with a capacity of 0
        cap[u][v] = c;
    }
    vector<vector<long>> original_cap = cap;

    long maxflow = max_flow(s, t);
    int edge_count = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (original_cap[i][j] > 0 && original_cap[i][j] - cap[i][j] > 0) {
                edge_count++;
            }
        }
    }

    cout << n << " " << maxflow << " " << edge_count << "\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            long flow = original_cap[i][j] - cap[i][j];
            if (original_cap[i][j] > 0 && flow > 0) {
                cout << i << " " << j << " " << flow << "\n";
            }
        }
    }
}