#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> adj;
vector<int> dest;
vector<int> status;  // -1 for inactive, 0 for unexplored, and 1 for active

int main() {
    int n, m;
    cin >> n >> m;

    adj.assign(n, vector<int>());
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        adj[a].push_back(b);
    }

    // Sorting the adjacency list
    for (auto& x : adj) sort(x.begin(), x.end());

    dest.assign(m, 0);
    for (auto& x : dest) cin >> x;
    
    status.assign(n, 0);
    int count = 0;
    vector<bool> vis(n, false);
    vector<int> stack;
    stack.push_back(0);
    vis[0] = true;
    status[0] = 1;
    for (int i = 0; i < m; i++) {
        if (status[dest[i]] == 1) {
            count++;
            continue;
        } else if (status[dest[i]] == -1) {
            break;
        } else {
            // Unexplored - DFS
            cout << dest[i] << '\n';
            while (!stack.empty()) {
                int node = stack.back();
                cout << node << '\n';

                for (int v : adj[node]) {
                    if (!vis[v]) {
                        stack.push_back(v);
                        status[v] = 1;
                        vis[v] = true;

                        if (status[dest[i]] == 1) {
                            count++;
                            break;
                        }
                    }
                }

                // Removing from the stack
                status[stack.back()] = -1;
                stack.pop_back();
            }
        }
    }

    cout << count << '\n';
}