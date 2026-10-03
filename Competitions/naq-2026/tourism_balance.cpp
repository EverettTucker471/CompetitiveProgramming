#include <bits/stdc++.h>

using namespace std;

int cycle = -1;
vector<bool> explored;
vector<int> parent;
vector<vector<int>> adj;

vector<int> dsu_parent;
vector<int> dsu_rank;

/**
 * Adds a value to the disjoint set
 */
void makeSet(int v) {
    dsu_parent[v] = v;
    dsu_rank[v] = 0;
}

/**
 * Finds the representative of the set containing v
 * Implements path compression
 */
int findSet(int v) {
    if (v == dsu_parent[v]) return v;
    return dsu_parent[v] = findSet(dsu_parent[v]);
}

/**
 * Merge two vertices' sets into one
 * Implements union by rank
 */
void unionSets(int a, int b) {
    a = findSet(a);
    b = findSet(b);
    if (a != b) {
        if (dsu_rank[a] < dsu_rank[b]) {
            swap(a, b);
        }
        dsu_parent[b] = a;
        if (dsu_rank[a] == dsu_rank[b]) {
            dsu_rank[a]++;
        }
    }
}

void dfs(int u) {
    explored[u] = true;
    for (int v : adj[u]) {
        if (v == parent[u]) continue;
        parent[v] = u;
        if (!explored[v]) {
            dfs(v);
        } else {
            cycle = v;
            return;
        }
    }
}

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> values(n);
    for (auto& x : values) cin >> x;

    adj.assign(n, vector<int>());
    for (int i = 0; i < n; i++) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // Finding all nodes in the unique cycle
    explored.assign(n, false);
    parent.assign(n, -1);
    dfs(0);

    int node = cycle;
    vector<bool> cycle_nodes(n, false);
    while (parent[node] != cycle) {
        cycle_nodes[node] = true;
        node = parent[node];
    }
    cycle_nodes[node] = true;
    
    // BFS starting from each of the cycle nodes
    dsu_parent.assign(n, -2);
    dsu_rank.assign(n, 0);

    queue<int> q;
    for (int i = 0; i < n; i++) {
        if (cycle_nodes[i]) {
            q.push(i);
            makeSet(i);
            explored[i] = true;
        } else {
            explored[i] = false;
        }
    }

    while (!q.empty()) {
        int node = q.front();
        explored[node] = true;
        q.pop();

        for (int v : adj[node]) {
            if (!explored[v]) {
                makeSet(v);
                unionSets(node, v);
                q.push(v);
            }
        }
    }

    // Now finally go through the target nodes
    map<int, vector<int>> value_map;
    for (int i = 0; i < n; i++) {
        value_map[values[i]].push_back(i);
    }

    // Make an array of hashmaps for each branch
    vector<map<int, int>> maps(n);
    for (int i = 0; i < n; i++) {
        int idx = findSet(i);
        maps[idx][values[i]]++;
    }

    // Computing as if everything was a 2
    long rtn = 0;
    for (auto x : value_map) {
        int target = k + x.first;
        if (value_map.count(target)) {
            rtn += 2 * x.second.size() * value_map[target].size();
        }
    }

    for (int i = 0; i < n; i++) {
        if (!maps[i].empty()) {
            for (auto x : maps[i]) {
                int target = k + x.first;
                if (maps[i].count(target)) {
                    rtn -= x.second * maps[i][target];  // Subtracting 1 to get from 2 to 1
                }
            }
        }
    }

    cout << rtn << endl;
}