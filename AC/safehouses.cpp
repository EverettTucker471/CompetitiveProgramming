#include<vector>
#include<iostream>
#include<unordered_map>
#include<map>
#include<unordered_set>
#include<set>
#include<cmath>
#include <algorithm>

using namespace std;

void safehouses() {
    int n;
    cin >> n;

    vector<pair<int, int>> spies;
    vector<pair<int, int>> houses;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            char c;
            cin >> c;
            if (c == 'H') {
                houses.emplace_back(i, j);
            } else if (c == 'S') {
                spies.emplace_back(i, j);
            }
        }
    }

    int max = 0;
    for (auto spy : spies) {
        int min = 2 * n;
        for (auto house : houses) {
            int dist = std::abs(house.first - spy.first) + std::abs(house.second - spy.second);
            if (dist < min) {
                min = dist;
            }
        }
        if (min > max) {
            max = min;
        }
    }

    cout << max << endl;
}