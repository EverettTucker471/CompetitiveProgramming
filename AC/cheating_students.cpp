#include<vector>
#include<iostream>
#include<unordered_map>
#include<map>
#include<unordered_set>
#include<set>
#include<cmath>
#include <algorithm>
#include <climits>
#include <numeric>

using namespace std;

vector<int> parent(2000, 0);
vector<int> dsu_rank(2000, 0);

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

void cheating_students() {
    int n;
    cin >> n;

    vector<pair<int, int>> points(n);
    for (auto& x : points) {
        cin >> x.first;
        cin >> x.second;
    }

    vector<vector<int>> edges;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            edges.push_back({abs(points[i].first - points[j].first) + 
                            abs(points[i].second - points[j].second), i, j});
        }
    }

    std::sort(edges.begin(), edges.end());

    /*
    for (auto x : edges) {
        cout << "Weight: " << x[0] << " From " << x[1] << " to " << x[2] << endl;
    }
    */

    // Init the dsu
    for (int i = 0; i < 2000; i++) {
        parent[i] = i;
    }

    long long rtn = 0;
    for (auto edge : edges) {
        if (findSet(edge[1]) != findSet(edge[2])) {
            rtn += edge[0];
            unionSets(edge[1], edge[2]);
        }
    }

    // Times 2 to get there and back from their seat
    cout << 2 * rtn << endl;
}

int main() {
    cheating_students();
    return 0;
}