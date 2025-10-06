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

void c22() {
    int _;
    cin >> _;

    while (_--) {
        int n;
        cin >> n;
        string s;
        cin >> s;

        vector<int> partial(n + 1, 0);
        for (int i = 0; i < n; i++) {
            if (s[i] == 'a') {
                partial[i + 1]++;
            } else {
                partial[i + 1]--;
            }
            partial[i + 1] += partial[i];
        }

        int diff = partial[n];
        if (diff == 0) {
            cout << 0 << endl;
            continue;
        }
        unordered_map<int, vector<int>> map;

        for (int i = 0; i < n; i++) {
            map[partial[i] - diff].push_back(i);
        }

        for (auto& x : map) reverse(x.second.begin(), x.second.end());
        /*
        for (auto x : map) {
            cout << x.first << " : ";
            for (auto y : x.second) {
                cout << y << " ";
            }
            cout << endl;
        }

        for (auto x : partial) {
            cout << x << " ";
        }
        cout << endl;
        */

        int rtn = n;
        for (int i = 0; i < n; i++) {
            if (map.count(partial[i])) {
                while (!map[partial[i]].empty() && map[partial[i]].back() <= i) map[partial[i]].pop_back();
                if (!map[partial[i]].empty()) rtn = min(rtn, map[partial[i]].back() - i);
            }
        }

        cout << (rtn == n ? -1 : rtn) << endl;
    }
}