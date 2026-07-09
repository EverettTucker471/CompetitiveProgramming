#include <bits/stdc++.h>

using namespace std;

vector<int> parent;
vector<int> dsu_rank;

/**
 * Adds a value to the disjoint set
 */
void makeSet(int v) {
    parent[v] = v;
    dsu_rank[v] = 0;
}

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
        if (dsu_rank[a] < dsu_rank[b]) {
            swap(a, b);
        }
        parent[b] = a;
        if (dsu_rank[a] == dsu_rank[b]) {
            dsu_rank[a]++;
        }
    }
}