#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> edges;
vector<bool> explored;
vector<int> colors;

bool dfs(int i, int parity) {
    explored[i] = true;
    colors[i] = parity;
    bool rtn = true;
    for (auto v : edges[i]) {
        if (colors[v] == parity) {
            return false;
        } else if (!explored[v]) {
            rtn &= dfs(v, parity * -1);
        }
    }
    return rtn;
}

int main() {
    int n;
    cin >> n;

    vector<string> strs(n);
    unordered_map<std::string, int> map;
    for (int i = 0; i < n; i++) {
        std::string s;
        std::cin >> s;
        map[s] = i;
        strs[i] = s;
    }

    int m;
    cin >> m;
    // The edges that must exist in the bipartite graph
    edges.assign(n, vector<int>());

    for (int i = 0; i < m; i++) {
        string s, t;
        cin >> s >> t;
        edges[map[s]].push_back(map[t]);
        edges[map[t]].push_back(map[s]);
    }

    explored.assign(n, false);
    colors.assign(n, 0);

    for (int i = 0; i < n; i++) {
        if (!explored[i] && !dfs(i, 1)) {
            cout << "impossible" << endl;
            exit(0);
        }
    }

    for (int i = 0; i < n; i++) {
        if (colors[i] == 1) {
            cout << strs[i] << " ";
        }
    }
    cout << endl;
    for (int i = 0; i < n; i++) {
        if (colors[i] == -1) {
            cout << strs[i] << " ";
        }
    }
    cout << endl;
}