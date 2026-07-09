#include <bits/stdc++.h>

using namespace std;

long long int dist(pair<long long int, long long int> a, pair<long long int, long long int> b) {
    return (a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second);
}

int n, timer;
vector<vector<int>> adj;
vector<bool> visited;
vector<int> tin, low;
vector<pair<long long int, long long int>> pillars;
bool found;

void dfs(int v, int p = -1) {
    visited[v] = true;
    tin[v] = low[v] = timer++;
    int children = 0;
    for (int to : adj[v]) {
        if (to == 0) continue;
        if (visited[to]) {
            low[v] = min(low[v], tin[to]);
        } else {
            dfs(to, v);
            low[v] = min(low[v], low[to]);
            if (low[to] >= tin[v] && p != -1) {
                if (v != 0) found = true;
            }
            ++children;
        }
    }
    if (p == -1 && children > 1) {
        if (v != 0) found = true;
    }
}

bool check(double d) {
    timer = 0;
    found = false;
    visited.assign(n, false);
    tin.assign(n, -1);
    low.assign(n, -1);

    // Initializing adj
    adj.assign(n, vector<int>());
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (dist(pillars[i], pillars[j]) < d) {
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(i);
        }
    }

    return found;
}

int main() {
    cin >> n;

    pillars.push_back({0, 0});
    for (int i = 0; i < n; i++) {
        pair<long long int, long long int> x;
        cin >> x.first >> x.second;
        pillars.push_back(x);
    }

    if (n == 2) {
        printf("%.8lf\n", sqrt(dist(pillars[0], pillars[1])));
        exit(0);
    }

    long long int left = 0;
    long long int right = LLONG_MAX;
    while (left <= right) {
        double mid = (left + right) / 2;

        if (check(sqrt(mid))) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    printf("%.8lf\n", sqrt(left));
}