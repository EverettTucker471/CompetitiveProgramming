#include <bits/stdc++.h>

using namespace std;

vector<bool> visited;

void search(int v, vector<vector<int>> const& adj, vector<int> &ordering) {
    visited[v] = true;
    for (int j : adj[v]) {
        if (!visited[j]) search(j, adj, ordering);
    }
    ordering.push_back(v);
}

/**
 * Gets the strongly connected components of a directed graph
 * @param adj the adjacency list of the directed graph
 * @return the strongly connected components
 */
vector<vector<int>> scc(vector<vector<int>> const &adj) {
    int n = (int) adj.size();  // Number of nodes in the graph
    vector<vector<int>> rtn;  // The list of strongly connected components
    vector<int> ordering;  // The topological ordering
    visited.assign(n, false);  // Stores if vertex i has been visited

    // First searchDFS
    for (int i = 0; i < n; i++) {
        if (!visited[i]) search(i, adj, ordering);
    }

    // Creating transpose graph
    vector<vector<int>> adj_t(n, vector<int>());
    for (int i = 0; i < n; i++) {
        for (int j : adj[i]) {
            adj_t[j].push_back(i);
        }
    }

    // Resetting visited and reversing order
    visited.assign(n, false);
    reverse(ordering.begin(), ordering.end());

    // Second depth-first searchDFS
    for (int x : ordering) {
        if (!visited[x]) {
            vector<int> component;
            search(x, adj_t, component);
            rtn.push_back(component);
        }
    }

    return rtn;
}