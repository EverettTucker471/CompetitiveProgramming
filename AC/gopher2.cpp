#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> adj;
vector<int> matching;
vector<bool> used;

double dist(pair<double, double> x, pair<double, double> y) {
    return sqrt((x.first - y.first) * (x.first - y.first) + 
                (x.second - y.second) * (x.second - y.second));
}

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
    int n, m, s, v;

    while (cin >> n) {
        cin >> m >> s >> v;

        vector<pair<double, double>> gophers(n);
        vector<pair<double, double>> holes(m);

        for (auto& x : gophers) cin >> x.first >> x.second;
        for (auto& x : holes) cin >> x.first >> x.second;

        adj.assign(n, vector<int>());
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (dist(gophers[i], holes[j]) / v <= s) {
                    adj[i].push_back(j);
                }
            }
        }

        matching.assign(m, -1);
        for (int v = 0; v < n; v++) {
            used.assign(n, false);
            dfs(v);
        }

        int rtn = 0;
        for (auto x : matching) {
            if (x < 0) rtn++;
        }

        cout << rtn << "\n";
    }
}