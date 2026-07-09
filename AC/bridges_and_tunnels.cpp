#include <bits/stdc++.h>

using namespace std;

vector<int> parent;
vector<int> dsu_rank;

/**
 * Finds the representative of the set containing v
 * Implements path compression
 */
int findSet(int v) {
    if (v == parent[v]) return v;
    return parent[v] = findSet(parent[v]);
}

/**
 * Merge two vertices' sets into one
 * Implements union by rank
 */
void unionSets(int a, int b) {
    a = findSet(a);
    b = findSet(b);
    if (a != b) {
        parent[b] = a;
        dsu_rank[a] += dsu_rank[b];
    }
}

int main() {
    int n;
    cin >> n;

    int count = 0;

    for (int i = 0; i < 2 * n; i++) {
        parent.push_back(i);
        dsu_rank.push_back(1);
    }

    map<string, int> name_map;
    for (int i = 0; i < n; i++) {
        vector<string> b(2);
        for (auto& x : b) cin >> x;

        for (auto x : b) {
            if (!name_map.count(x)) {
                name_map[x] = count;
                count++;
            }
        }

        int x = name_map[b[0]];
        int y = name_map[b[1]]; 
        unionSets(x, y);
        cout << dsu_rank[findSet(x)] << '\n';
    }
}