#include <bits/stdc++.h>

using namespace std;

struct E {
    int v;
    int d;
    int b;

    E (int v, int d, int b) : v(v), d(d), b(b) {}


};

void rainbow_road() {
    vector<int> cmap(256);
    cmap['R'] = 1;
    cmap['O'] = 2;
    cmap['Y'] = 4;
    cmap['G'] = 8;
    cmap['B'] = 16;
    cmap['I'] = 32;
    cmap['V'] = 64;

    int n, m;
    cin >> n >> m;

    vector<vector<E>> adj(n, vector<E>());
    for (int i = 0; i < m; i++) {
        int l1, l2, d;
        char c;
        cin >> l1 >> l2 >> d;
        cin >> c;
        l1--;
        l2--;

        adj[l1].push_back(E(l2, d, cmap[c]));
        adj[l2].push_back(E(l1, d, cmap[c]));
    }
}