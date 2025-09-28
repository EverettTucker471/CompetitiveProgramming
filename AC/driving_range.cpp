#include<vector>
#include<iostream>
#include<cmath>
#include <algorithm>

using namespace std;
vector<int> aparents;

int afind(int i) {
    if (aparents[i] != i) {
        aparents[i] = afind(aparents[i]);
    }
    return aparents[i];
}

void driving_range() {
    int n, m;
    cin >> n >> m;

    vector<pair<int, pair<int, int>>> edges(m);
    for (auto& edge : edges) {
        cin >> edge.second.first;
        cin >> edge.second.second;
        cin >> edge.first;
    }

    sort(edges.begin(), edges.end());

    int count = 0;
    int rtn = 0;
    aparents.reserve(n);
    for (int i = 0; i < n; i++) {
        aparents.push_back(i);
    }

    for (auto edge : edges) {
        if (afind(edge.second.first) != afind(edge.second.second)) {
            rtn = std::max(rtn, edge.first);
            count++;
            aparents[afind(edge.second.first)] = afind(edge.second.second);
        }
    }

    if (count == n - 1) {
        cout << rtn << endl;
    } else {
        cout << "IMPOSSIBLE";
    }
}