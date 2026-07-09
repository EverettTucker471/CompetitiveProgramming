#include <bits/stdc++.h>

using namespace std;

vector<bool> visited;

void searchDFS(int v, vector<vector<int>> const& adj, vector<int>& ordering) {
    visited[v] = true;
    for (int u : adj[v]) {
        if (!visited[u]) searchDFS(u, adj, ordering);
    }
    ordering.push_back(v);
}

/**
 * Gets the topological ordering of a directed graph
 * @param adj the adjacency list of the graph
 * @return a list of the topological ordering
 */
vector<int> toposort(vector<vector<int>> const& adj) {
    int n = (int) adj.size();  // Number of nodes in the graph
    vector<int> rtn;  // Topological sorting of vertices

    for (int i = 0; i < n; i++) {
        if (!visited[i]) searchDFS(i, adj, rtn);
    }
    reverse(rtn.begin(), rtn.end());

    return rtn;
}