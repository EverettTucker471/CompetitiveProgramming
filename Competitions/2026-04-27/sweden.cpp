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
    int r, c, u;
    cin >> r >> c >> u;

    int start = 0;
    dsu_rank.assign(r * c, 0);
    vector<vector<char>> grid(r, vector<char>(c));
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> grid[i][j];
            if (grid[i][j] != '.') dsu_rank[i * c + j] = 1;
            if (grid[i][j] == 'S') start = i * c + j;
        }
    }

    parent.assign(r * c, -1);
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            parent[i * c + j] = i * c + j;
        }
    }

    for (int i = 1; i < r; i++) {
        for (int j = 1; j < c; j++) {
            if (grid[i][j] != '.') {
                int point = i * c + j;
                if (grid[i - 1][j] != '.') unionSets(point, point - 1);
                if (grid[i][j - 1] != '.') unionSets(point, point - c);
            }
        }
    }

    cout << dsu_rank[findSet(start)] << "\n"; 
    for (int k = 0; k < u; k++) {
        int i, j;
        cin >> i >> j;
        i--;
        j--;
        int point = i * c + j;
        if (i > 0) unionSets(point, point - c);
        if (j > 0) unionSets(point, point - 1);
        if (i < r - 1) unionSets(point, point + c);
        if (j < c - 1) unionSets(point, point + 1);

        cout << dsu_rank[findSet(start)] << "\n";
    }
}