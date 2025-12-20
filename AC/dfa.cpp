#include <bits/stdc++.h>

using namespace std;

void dfa() {
    int n, c, s, f;
    cin >> n >> c >> s >> f;

    string _;
    cin >> _;

    s--;
    vector<bool> final_states(n, false);
    vector<int> dist(n, INT_MAX);
    for (int i = 0; i < f; i++) {
        int x;
        cin >> x;
        final_states[x - 1] = true;
    }

    vector<vector<int>> adj(n, vector<int>());

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < c; j++) {
            int x;
            cin >> x;
            adj[i].push_back(x - 1);
        }
    }

    queue<int> queue;
    queue.push(s);
    dist[s] = 0;

    while (!queue.empty()) {
        int node = queue.front();
        queue.pop();

        for (int next : adj[node]) {
            if (dist[next] == INT_MAX) queue.push(next);
            dist[next] = min(dist[next], dist[node] + 1);
        }
    }

    int rtn = INT_MAX;
    for (int i = 0; i < n; i++) {
        if (final_states[i]) {
            rtn = min(rtn, dist[i]);
        }
    }

    cout << rtn << endl;
}