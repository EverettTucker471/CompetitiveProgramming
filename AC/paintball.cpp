#include <bits/stdc++.h>

using namespace std;

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


int main() {
    int n, m;
    cin >> n >> m;

    adj.assign(n, vector<int>());
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    matching.assign(n, -1);
    for (int v = 0; v < n; v++) {
        used.assign(n, false);
        dfs(v);
    }

    int count = 0;
    for (auto x : matching) {
        if (x >= 0) count++;
    }

    if (count == n) {
        for (int i = 0; i < n; i++) {
            cout << matching[i] + 1 << "\n";
        }
    } else {
        cout << "Impossible\n";
    }
}