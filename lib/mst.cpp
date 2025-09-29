#include <vector>
#include <iostream>
#include <unordered_map>
#include <map>
#include <unordered_set>
#include <set>
#include <cmath>
#include <algorithm>
#include <climits>
#include <numeric>
#include "dsu.cpp"

using namespace std;

struct Edge {
    int u, v;
    double weight;
    bool operator<(Edge const& other) {
        return weight < other.weight;
    }
};

/** 
 * Computes the MST from the edges and the number of nodes
 * Returns the cost by reference
 */
vector<Edge> kruskals(vector<Edge> edges, double& cost, int n) {
    cost = 0;
    vector<Edge> rtn;

    // Using the parent and dsu_rank vectors from dsu.cpp
    parent.resize(n);
    dsu_rank.resize(n);

    for (int i = 0; i < n; i++) makeSet(i);

    sort(edges.begin(), edges.end());

    for (Edge e : edges) {
        if (findSet(e.u) != findSet(e.v)) {
            cost += e.weight;
            rtn.push_back(e);
            unionSets(e.u, e.v);
        }
    }

    return rtn;
}
