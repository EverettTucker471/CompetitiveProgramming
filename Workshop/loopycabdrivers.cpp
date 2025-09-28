#include<vector>
#include<iostream>
#include<unordered_map>
#include<map>
#include<unordered_set>
#include<set>
#include<cmath>
#include <algorithm>

using namespace std;

void traverse(vector<int>& color, vector<int>* order, const vector<vector<int>>& adj, int i) {
    color[i] = 1;

    for (int j : adj[i]) {
        if (!color[j]) traverse(color, order, adj, j);
    }
    order->push_back(i);
}

void traverse2(vector<int>& color, vector<vector<int>>* comp, const vector<vector<int>>& adj, int i, int k) {
    color[i] = 1;

    for (int j : adj[i]) {
        if (!color[j]) traverse2(color, comp, adj, j, k);
    }

    comp->at(k).push_back(i);
}

void loopycabdrivers() {
    int n;
    cin >> n;

    vector<pair<string, string>> edge_list;
    vector<string> names;
    int index = 0;
    unordered_map<string, int> map;
    for (int i = 0; i < n; i++) {
        string a, b;
        cin >> a >> b;

        if (!map.count(a)) {
            names.push_back(a);
            map[a] = index;
            index++;
        }
        if (!map.count(b)) {
            names.push_back(b);
            map[b] = index;
            index++;
        }

        edge_list.emplace_back(a, b);
    }

    n = index;  // n is now the number of vertices
    vector<vector<int>> adj(n, vector<int>());
    for (const auto& x : edge_list) {
        adj[map[x.first]].push_back(map[x.second]);
    }

    vector<int> color(n, 0);
    vector<int> order;
    for (int i = 0; i < n; i++) {
        if (!color[i]) traverse(color, &order, adj, i);
    }

    // Reverse adj
    vector<vector<int>> adj_reverse(n, vector<int>());
    for (int i = 0; i < n; i++) {
        for (auto x : adj[i]) {
            adj_reverse[x].push_back(i);
        }
    }

    color.assign(n, 0);
    index = 0;
    vector<vector<int>> comp;
    for (int i = n - 1; i >= 0; i--) {
        if (!color[i]) {
            comp.emplace_back();
            traverse2(color, &comp, adj_reverse, i, index);
            index++;
        }
    }

    for (const auto& x : comp) {
        for (auto y : x) {
            cout << names[y] << " ";
        }
        cout << endl;
    }

    for (auto x : order) {
        cout << names[x] << " ";
    }

    /*
    for (int i = 0; i < adj.size(); i++) {
        cout << names[i] << " ";
        for (auto x : adj[i]) {
            cout << names[x] << " ";
        }
        cout << endl;
    }
     */
}