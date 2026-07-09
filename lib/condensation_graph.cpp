#include <bits/stdc++.h>

using namespace std;

vector<bool> visited;

void dfs(int v, vector<vector<int>> const& adj, vector<int>& ordering) {
    visited[v] = true;
    for (int u : adj[v]) {
        if (!visited[u]) dfs(u, adj, ordering);
    }
    ordering.push_back(v);
}

/**
 * Gets the condensation graph of a directed graph
 * The condensation graph replaces all strongly-connected-components
 * with a single vertex
 * @param adj the adjacency list of the original graph
 * @return the adjacency list of the condensation graph
 */
vector<vector<int>> condensation_graph(vector<vector<int>> const& adj) {
    int n = (int) adj.size();
    vector<vector<int>> rtn;
    vector<vector<int>> sccs;
    vector<int> order;

    // First searchDFS
    for (int i = 0; i < n; i++) {
        if (!visited[i]) dfs(i, adj, order);
    }

    // Getting transpose adjacency list
    vector<vector<int>> adj_t(n, vector<int>());
    for (int i = 0; i < n; i++) {
        for (int j : adj[i]) {
            adj_t[j].push_back(i);
        }
    }

    // Resetting visited and reversing the order to proper topological
    visited.assign(n, false);
    reverse(order.begin(), order.end());
    vector<int> roots(n, 0);

    // Second searchDFS
    for (auto x : order) {
        if (!visited[x]) {
            vector<int> component;
            dfs(x, adj_t, component);
            sccs.push_back(component);
            // Setting roots for a simple DSU Data Structure
            int root = *min_element(begin(component), end(component));
            for (int u : component) {
                roots[u] = root;
            }
        }
    }

    // Creating condensation graph
    rtn.assign(n, {});
    for (int i = 0; i < n; i++) {
        for (auto u : adj[i]) {
            // Only adding vertices that are in different sccs
            if (roots[i] != roots[u]) rtn[roots[i]].push_back(roots[u]);
        }
    }

    return rtn;
}