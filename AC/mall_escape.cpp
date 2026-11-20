#include <bits/stdc++.h>

using namespace std;

int n, e;
vector<vector<int>> adj;
int BIG = 1000000;

void bfs(int start, vector<int>& dist) {
    dist[start] = 0;
    queue<pair<int, int>> q;
    q.push({0, start});
    while (!q.empty()) {
        auto p = q.front();
        q.pop();
        int cost = p.first;
        int u = p.second;

        if (cost > dist[u]) continue;
        for (int v : adj[u]) {
            int alt = cost + 1;
            if (alt < dist[v]) {
                dist[v] = alt;
                q.push({alt, v});
            }
        }
    }
}

int main() {
    cin >> n >> e;

    adj.assign(n, vector<int>());
    for (int i = 0; i < e; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<int> distHuman(n, BIG);
    vector<int> distZombie(n, BIG);
    bfs(0, distHuman);
    bfs(n - 1, distZombie);

    vector<bool> accessible(n, false);
    accessible[0] = true;
    queue<int> q;
    q.push(0);

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : adj[u]) {
            if (accessible[v]) continue;
            int a = distHuman[v];
            int b = distZombie[v];
            if (a < b) {
                accessible[v] = true;
                q.push(v);
            } else if (a == b) {
                accessible[v] = true;
            } else if (a == b + 1 && distHuman[u] == b) {
                accessible[v] = true;
            }
        }
    }

    vector<double> prob(n, 0.0);
    prob[n - 1] = 1.0;
    vector<bool> vis(n, false);
    vis[n - 1] = true;
    queue<int> q2;
    q2.push(n - 1);
    
    while (!q2.empty()) {
        int u = q2.front();
        q2.pop();
        int split = 0;
        for (int v : adj[u]) {
            if (distZombie[v] <= distZombie[u]) continue;
            split++;
            if (!vis[v]) {
                q2.push(v);
                vis[v] = true;
            }
        }

        if (split == 0) continue;
        double inc = prob[u] / split;
        for (int v : adj[u]) {
            if (distZombie[v] <= distZombie[u]) continue;
            prob[v] += inc;
        }
    }

    double ans = 1.0;
    for (int i = 0; i < n; i++) {
        if (accessible[i]) ans = min(ans, prob[i]);
    }

    printf("%.17e\n", ans);
}