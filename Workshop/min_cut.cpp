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
                long new_flow = min(flow, cap[next][cur]);
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

    adj.assign(n, vector<int>());
    cap.assign(n, vector<long>(n, 0));
    for (int i = 0; i < m; i++) {
        int u, v, c;
        cin >> u >> v >> c;

        adj[u].push_back(v);
        adj[v].push_back(u);
        cap[u][v] = c;
    }
    vector<vector<long>> original_cap = cap;

    max_flow(s, t);

    // Constructing the partition with a BFS
    set<int> partition;
    queue<int> q;
    q.push(s);
    while (!q.empty()) {
        int node = q.front();
        partition.insert(node);
        q.pop();

        for (int v : adj[node]) {
            if (!partition.count(v) && original_cap[node][v] && original_cap[node][v] != cap[node][v]) {
                q.push(v);
            }
        }
    }

    cout << partition.size() << "\n";
    for (int x : partition) cout << x << "\n";
}