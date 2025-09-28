#include<vector>
#include<iostream>
#include<unordered_map>
#include<map>
#include<unordered_set>
#include<set>
#include<cmath>
#include<climits>
#include <algorithm>

using namespace std;

void a15() {
    int n, m;
    cin >> n >> m;

    // Not enough edges
    if (m < n - 1) {
        cout << -1;
        return;
    }

    // Try to add as many edges as possible - use some ordering
    vector<pair<int, int>> edges;
    for (int i = 0; i < n - 1; i++) {
        edges.emplace_back(1, i + 2);
    }

    // Graph is now connected, try to add more edges
    // The sum is at 1 + n,
    for (int i = 2; i < n; i++) {
        edges.emplace_back(i, n);
    }

    if (m > edges.size()) {
        cout << -1;
        return;
    }

    for (int i = 0; i < m; i++) {
        cout << edges[i].first << " " << edges[i].second << endl;
    }
}