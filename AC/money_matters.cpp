#include <bits/stdc++.h>

using namespace std;

vector<bool> visited;
vector<int> bal;
vector<vector<int>> adj;

int dfs(int v) {
    int rtn = bal[v];
    visited[v] = true;
    for (int x : adj[v]) {
        if (!visited[x]) {
            rtn += dfs(x);
        }
    }

    return rtn;
}

int main() {
    // If each connected component has a net zero sum

    int n, m;
    cin >> n >> m;

    bal.assign(n, 0);
    adj.assign(n, vector<int>());
    for (auto& x : bal) cin >> x;

    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    visited.assign(n, false);
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            if (dfs(i) != 0) {
                cout << "IMPOSSIBLE\n";
                exit(0);
            }
        }
    }

    cout << "POSSIBLE\n";
}