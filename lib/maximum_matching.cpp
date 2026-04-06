#include <bits/stdc++.h>

using namespace std;

int n; // Number of vertices in the left partition
int m; // Number of vertices in the right partition
vector<vector<int>> adj;
vector<int> matching;
vector<bool> used;

bool dfs(int v) {
    if (used[v]) return false;
    used[v] = true;

    for (int u : adj[v]) {
        if (matching[u] == -1 || dfs(matching[u])) {
            matching[u] = v;
            return true;
        }
    }

    return false;
}

/**
 * Solves the maximum matching problem
 * for an unweighted bipartite graph
 */
void maximum_matching() {
    matching.assign(m, -1);
    for (int v = 0; v < n; v++) {
        used.assign(n, false);
        dfs(v);
    }
}