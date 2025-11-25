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

struct {
    double dist;
    int u;
    int v;
} typedef Point;

bool comp(const Point& a, const Point& b) {
        return a.dist < b.dist;
}

vector<int> parent;
vector<int> dsu_rank;

/**
 * Adds a value to the disjoint set
 * Rank now keeps track of the number of elements in that tree
 */
void makeSet(int v) {
    parent[v] = v;
    dsu_rank[v] = 1;
}

/**
 * Finds the representative of the set containing v
 * Implements path compression
 */
int findSet(int v) {
    if (v == parent[v]) return v;
    return parent[v] = findSet(parent[v]);
}

int numComponents;

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
        numComponents--;
    }
}

void arctic_network() {
    // Binary search on connectedness, 
    // then see if our main graph is missing fewer than {num_channels} edges

    int _;
    cin >> _;

    while (_--) {
        int s, p;
        cin >> s >> p;

        vector<pair<int, int>> pos(p);
        for (auto& x : pos) {
            cin >> x.first;
            cin >> x.second;
        }

        vector<Point> edges;
        for (int i = 0; i < p; i++) {
            for (int j = i + 1; j < p; j++) {
                edges.push_back({std::sqrt(std::pow(pos[i].first - pos[j].first, 2) +
                                std::pow(pos[i].second - pos[j].second, 2)), i, j});
            }
        }

        std::sort(edges.begin(), edges.end(), comp);

        /*
        for (auto x : edges) {
            cout << x.dist << " " << x.u << " " << x.v << endl;
        }
        cout << endl;
        */

        // DSU until we hit p - s
        parent.reserve(p);
        dsu_rank.reserve(p);
        for (int i = 0; i < p; i++) makeSet(i);

        // At each point, compute the number of connected components

        numComponents = p;
        double rtn = edges[edges.size() - 1].dist;
        for (int i = 0; i < edges.size(); i++) {
            Point pt = edges[i];
            unionSets(pt.u, pt.v);
            // cout << numComponents << endl;
            if (numComponents - s < 1) {
                rtn = pt.dist;
                break;
            }
        }

        cout << printf("%.2f\n", rtn);
    }
}

int main() {
    arctic_network();
    return 0;
}