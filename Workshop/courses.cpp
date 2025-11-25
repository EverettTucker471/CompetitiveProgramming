#include<vector>
#include<iostream>
#include<unordered_map>
#include<map>
#include<unordered_set>
#include<set>
#include<cmath>
#include <algorithm>
#include <climits>
#include <numeric>

using namespace std;

vector<bool> visited;

void searchDFS(int v, vector<vector<int>> const& adj, vector<int>& ordering, int index) {
    visited[v] = index;
    for (int u : adj[v]) {
        if (!visited[u]) {
            searchDFS(u, adj, ordering, index);
        } else if (visited[u] == index) {
            cout << "Omogulegt!" << endl;
            exit(0);
        }
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
        if (!visited[i]) searchDFS(i, adj, rtn, i + 1);
    }
    reverse(rtn.begin(), rtn.end());

    return rtn;
}

void courses() {
    int n;
    cin >> n;

    vector<vector<int>> adj(n, vector<int>());
    for (int i = 0; i < n; i++) {
        int m;
        cin >> m;

        for (int j = 0; j < m; j++) {
            int x;
            cin >> x;
            adj[i].push_back(x - 1);
        }
    }

    for (int i = 0; i < n; i++) visited.push_back(0);
    vector<int> sorted = toposort(adj);

    vector<int> levelNumber(n, -1);
    for (int i = 0; i < n; i++) {
        int node = sorted[i];
        int max = -1;
        for (auto x : adj[node]) {
            max = std::max(max, levelNumber[x]);
        }
        levelNumber[node] = max + 1;
    }

    int numSemesters = 0;
    for (int x : levelNumber) numSemesters = std::max(numSemesters, x);

    vector<vector<int>> rtn(numSemesters + 1, vector<int>());
    for (int i = 0; i < n; i++) {
        rtn[levelNumber[i]].push_back(i);
    }

    cout << rtn.size() << endl;
    for (int i = 0; i <= numSemesters; i++) {
        cout << rtn[i].size() << " ";
        for (auto x : rtn[i]) {
            cout << x + 1 << " ";
        }
        cout << endl;
    }
}

int main() {
    courses();
    return 0;
}