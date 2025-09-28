#include<vector>
#include<iostream>
#include<cmath>
#include <algorithm>

using namespace std;
int parents[750];

int find(int i) {
    if (parents[i] != i) {
        return find(parents[i]);
    }
    return i;
}

void island_hopping() {
    int _;
    cin >> _;

    while (_--) {
        int m;
        cin >> m;

        vector<pair<double, double>> p(m);
        for (auto& x : p) {
            cin >> x.first;
            cin >> x.second;
        }

        vector<pair<double, pair<int, int>>> edges;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < i; j++) {
                edges.push_back({sqrt(pow(p[i].first - p[j].first, 2) + pow(p[i].second - p[j].second, 2)), {i, j}});
            }
        }

        sort(edges.begin(), edges.end());

        double rtn = 0;
        for (int i = 0; i < m; i++) {
            parents[i] = i;
        }

        for (auto edge : edges) {
            if (find(edge.second.first) != find(edge.second.second)) {
                parents[find(edge.second.first)] = find(edge.second.second);
                rtn += edge.first;
            }
        }

        printf("%.4lf\n", rtn);
    }
}
