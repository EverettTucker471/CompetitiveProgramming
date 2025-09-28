#include<vector>
#include<iostream>
#include <queue>
#include <climits>

using namespace std;

void zoning() {
    int n;
    cin >> n;
    int n2 = n * n;

    vector<vector<char>> zones(n, vector<char>(n, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> zones[i][j];
        }
    }

    vector<bool> visited(n2, false);
    vector<int> dist(n2, INT_MAX);
    queue<int> q;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (zones[i][j] == '3') {
                q.push(i * n + j);
                dist[i * n + j] = 0;
                visited[i * n + j] = true;
            }
        }
    }

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        // Up
        if (node - n >= 0 && !visited[node - n]) {
            q.push(node - n);
            dist[node - n] = min(dist[node] + 1, dist[node - n]);
            visited[node - n] = true;
        }

        // Down
        if (node + n < n2 && !visited[node + n]) {
            q.push(node + n);
            dist[node + n] = min(dist[node] + 1, dist[node + n]);
            visited[node + n] = true;
        }

        // Left
        if (node % n && !visited[node - 1]) {
            q.push(node - 1);
            dist[node - 1] = min(dist[node] + 1, dist[node - 1]);
            visited[node - 1] = true;
        }

        // Right
        if ((node + 1) % n && !visited[node + 1]) {
            q.push(node + 1);
            dist[node + 1] = min(dist[node] + 1, dist[node + 1]);
            visited[node + 1] = true;
        }
    }

    int rtn = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (zones[i][j] == '1') {
                rtn = max(rtn, dist[i * n + j]);
            }
        }
    }

    cout << rtn;
}