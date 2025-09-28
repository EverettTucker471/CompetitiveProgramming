#include<vector>
#include<iostream>
#include<unordered_map>
#include<map>
#include<unordered_set>
#include<set>
#include<cmath>
#include<climits>
#include <algorithm>
#include <queue>

using namespace std;

void interplanetary_tunnels() {
    int n, m, a, b;
    cin >> n >> m >> a >> b;

    vector<vector<int>> adj(n, vector<int>());
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;

        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    queue<int> q;
    vector<bool> visited(n, false);
    q.push(a);
    visited[a] = true;
    int next = 0;
    int cur = 1;
    int dist = 0;

    while (!q.empty() && !visited[b]) {
        int node = q.front();
        visited[node] = true;
        q.pop();
        cur--;

        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                q.push(neighbor);
                next++;
            }
        }

        if (cur == 0) {
            cur = next;
            next = 0;
            dist++;
        }
    }

    cout << (dist % 2 ? dist / 2 + 1 : dist / 2);
}