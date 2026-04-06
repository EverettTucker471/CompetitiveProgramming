#include <bits/stdc++.h>

using namespace std;

vector<vector<long long>> adj;
map<long long, int> matching;
vector<bool> used;

bool dfs(int v) {
    if (used[v]) return false;
    used[v] = true;

    for (long long u : adj[v]) {
        if (!matching.count(u) || dfs(matching[u])) {
            matching[u] = v;
            return true;
        }
    }

    return false;
}

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> nums;
    adj.assign(n, vector<long long>());
    for (int i = 0; i < n; i++) {
        long long x, y;
        cin >> x >> y;
        nums.emplace_back(x, y);
        adj[i].push_back(x + y);
        adj[i].push_back(x - y);
        adj[i].push_back(x * y);
    }

    for (int v = 0; v < n; v++) {
        used.assign(n, false);
        dfs(v);
    }

    int count = 0;
    for (auto x : matching) count++;

    if (count == n) {
        vector<long long> result(n);
        for (auto x : matching) {
            result[x.second] = x.first;
        }

        for (int i = 0; i < n; i++) {
            pair<int, int> p = nums[i];

            if (p.first + p.second == result[i]) {
                cout << p.first << " + " << p.second << " = " << result[i] << "\n";
            } else if (p.first - p.second == result[i]) {
                cout << p.first << " - " << p.second << " = " << result[i] << "\n";
            } else {
                cout << p.first << " * " << p.second << " = " << result[i] << "\n";
            } 
        }
    } else {
        cout << "impossible\n";
    }
}