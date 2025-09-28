// Try to group the items into two sets such that there is no overlap
// Construct a map of the names

#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

/*
 * This determines if the given graph is bipartite using a searchDFS and a vector that stores parity
 * Look at maximal matching algorithm, very short but effective
 */
using namespace std;

vector<vector<int>> edges;
vector<bool> explored;
vector<int> colors;

bool dfs(int i, int parity) {
    explored[i] = true;
    colors[i] = parity;
    bool rtn = true;
    for (auto edge : edges[i]) {
        if (colors[edge] == parity) {
            return false;
        } else if (!explored[edge]) {
            rtn = rtn && dfs(edge, parity * -1);}
    }
    return rtn;
}

void breaking_bad() {
    int n;
    cin >> n;

    unordered_map<std::string, int> map;
    for (int i = 0; i < n; i++) {
        std::string s;
        std::cin >> s;
        map[s] = i;
    }

    int m;
    std::cin >> m;
    // The edges that must exist in the bipartite graph
    vector<vector<int>> edges(m, vector<int>());

    for (int i = 0; i < m; i++) {
        string s;
        string t;
        std::cin >> s >> t;
        cout << s << t;
        edges[map[s]].push_back(map[t]);
        edges[map[t]].push_back(map[s]);
    }

    vector<bool> explored(n, false);
    vector<int> colors(n, 0);

    /*
    for (int i = 0; i < n; i++) {
        // Parity is 1 by default
        if (!explored[i] && !searchDFS(i, explored, colors, edges, 1)) {
            cout << "impossible";
            return;
        }
    }
     */

    // Print the colors
    cout << "possible";
}