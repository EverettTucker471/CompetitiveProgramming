#include <bits/stdc++.h>

using namespace std;

const int N = 2500;
vector<vector<int>> adj;
vector<int> matching;
vector<bool> used;

bool dfs(int v) {
    if (matching[v] > 0) return false;

    for (int u : adj[v]) {
        if (matching[u] == -1 || dfs(matching[u])) {
            matching[u] = v;
            matching[v] = u;
            return true;
        }
    }
    return false;
}

int main() {
    /*
    * Hash every unique antenna (position and orientation) into a number
    * The do a maximum matching from antennas to hashed antenna
    * The answer is n - (number of matches) / 2
    */

    int _;
    cin >> _;
    while (_--) {
        int h, w;
        cin >> h >> w;
        vector<pair<int, int>> pois;
        
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                char c;
                cin >> c;
                if (c == '*') pois.emplace_back(i, j);
            }
        }

        // Creating the adjacency list from hashed positions+orientations
        int num_ant = pois.size();
        vector<vector<int>> antennas(num_ant);
        
        for (int i = 0; i < num_ant; i++) {
            int p = pois[i].first * 50 + pois[i].second;
            for (int mod : {1, -1, 50, -50}) {
                // Antennas are uniquely characterized by two adjacent points
                antennas[i].push_back(N * max(p, p + mod) + min(p, p + mod));
            }
        }

        // Generating adjacency list from overlaps
        adj.assign(num_ant, vector<int>());
        for (int i = 0; i < num_ant; i++) {
            for (int j = i + 1; j < num_ant; j++) {
                bool flag = false;
                for (auto x : antennas[i]) {
                    for (auto y : antennas[j]) {
                        if (x == y) {
                            adj[i].push_back(j);
                            adj[j].push_back(i);
                            flag = true;
                            break;
                        }
                        if (flag) break;
                    }
                }
            }
        }

        for (int i = 0; i < num_ant; i++) {
            cout << i << " : ";
            for (auto x : adj[i]) {
                cout << x << " ";
            }
            cout << endl;
        }

        int count = 0;
        matching.assign(num_ant, -1);
        used.assign(num_ant, false);
        for (int v = 0; v < num_ant; v++) {
            if (dfs(v)) count++;
        }

        for (int i = 0; i < num_ant; i++) {
            cout << i << " " << matching[i] << endl;
        }

        cout << num_ant - count << "\n";
    }
}
