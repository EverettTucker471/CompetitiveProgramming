#include <bits/stdc++.h>

using namespace std;

int main() {
    /**
     * Searching for a valid k+1 coloring
     * of the nodes
     */
    int n, m, k;
    cin >> n >> m >> k;

    vector<vector<int>> adj(n);
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    // Greedy approach
    vector<int> assign(n, -1);
    vector<bool> visited(n, false);

    // Initial
    for (int start = 0; start < n; start++) {
        if (visited[start]) continue;
        queue<int> q;
        q.push(start);
        assign[start] = 0;
        visited[start] = true;

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            vector<int> pos;
            for (int v : adj[u]) {
                if (assign[v] >= 0) pos.push_back(assign[v]);
                if (!visited[v]) {
                    visited[v] = true;
                    q.push(v);
                }
            }

            // cout << "Node: " << u << '\n';
            sort(pos.begin(), pos.end());
            // for (auto x : pos) cout << x << " ";
            // cout << '\n';
            int mex = pos.size();
            for (int l = 0; l < pos.size(); l++) {
                if (pos[l] != l) {
                    mex = l;
                    break;
                }
            }
            assign[u] = mex;
            // for (auto x : assign) cout << x << " ";
            // cout << '\n';
        }
    }
    

    for (auto x : assign) cout << max(x + 1, 1) << " ";
    cout << '\n';
}