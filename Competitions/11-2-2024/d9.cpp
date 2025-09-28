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

bool count_layer(vector<int> layer) {
    int rtn = 0;
    int n = layer.size();
    for (int i = 0; i < n; i++) {
        if (layer[i] == 1 && layer[(i + 1) % n] == 4 && layer[(i + 2) % n] == 5 && layer[(i + 3) % n] == 3) {
            rtn++;
        }
    }
    return rtn;
}

void d9() {
    int _;
    cin >> _;

    while (_--) {
        int n, m;
        cin >> n >> m;

        int a[n][m];
        for (auto& x : a) {
            for (auto& y : x) {
                cin >> y;
            }
        }

        for (int i = 0; i < min(n, m); i++) {
            vector<int> layer;

        }
    }
}