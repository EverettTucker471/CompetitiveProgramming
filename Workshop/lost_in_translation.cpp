#include <vector>
#include <iostream>
#include <climits>
#include <unordered_map>
#include <queue>

using namespace std;

void lost_in_translation() {
    /**
     * Minimum spanning tree?
     * Consider minimum distance first, then cost
     * Use a BFS to check the distance condition first
     * Once the BFS hits all nodes, add all explored edges
     * and do an MST off of those edges
     *
     * Perhaps you could also use Dijkstra's with a special comparison function
    */

    int n, m;
    cin >> n >> m;
    unordered_map<string, int> map;

    map["English"] = 0;
    for (int i = 1; i <= n; i++) {
        string s;
        cin >> s;
        map[s] = i;
    }

    // Edge, weight pair
    vector<vector<pair<int, int>>> adj(n + 1, vector<pair<int, int>>());

    for (int i = 0; i < m; i++) {
        string s, t;
        cin >> s >> t;
        int w;
        cin >> w;

        adj[map[s]].emplace_back(map[t], w);
        adj[map[t]].emplace_back(map[s], w);
    }

    // BFS to find the included nodes and edges

    // Stores the good edges: {weight, to, from} pairs
    vector<vector<int>> edges;
    vector<bool> explored(n + 1, false);

    int count = 1;
    queue<int> queue;
    queue.push(0);
    explored[0] = true;
    int cur = 1;
    int next = 0;
    bool done = false;
    while (!queue.empty()) {
        int node = queue.front();
        queue.pop();

        if (!explored[node]) {
            for (auto x : adj[node]) {
                edges.push_back({x.second, node, x.first});
                queue.push(x.first);
                next++;
            }
            explored[node] = true;
        }
        cur--;
        count++;

        if (cur == 0) {
            if (done) {break;}
            cur = next;
            next = 0;
            if (count >= n) {
                done = true;
            }
        }
    }

    cout << edges.size();
    for (auto x : edges) {
        cout << x[0] << " " << x[1] << " " << x[2] << endl;
    }
}