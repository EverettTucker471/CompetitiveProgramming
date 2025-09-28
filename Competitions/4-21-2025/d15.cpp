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

double cross(pair<int, int> a, pair<int, int> b) {
    return a.first * b.second - b.first * a.second;
}

void d15() {
    int _;
    cin >> _;

    while (_--) {
        int n;
        cin >> n;

        vector<pair<int, int>> p(n);
        for (auto& x : p) {
            cin >> x.first >> x.second;
        }

        double rtn = 0;
        for (int i = 1; i < n - 1; i++) {
            rtn += cross({p[i].first - p[0].first, p[i].second - p[0].second},
                         {p[i + 1].first - p[0].first, p[i + 1].second - p[0].second});

        }

        cout << rtn / 2 << endl;
    }
}