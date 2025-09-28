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

void d8() {
    int _;
    cin >> _;

    while (_--) {
        int n, q;
        cin >> n >> q;
        int p[n];
        for (auto &x: p) {
            cin >> x;
        }
        string s;
        cin >> s;

        bool pos[n];  // pos[i] = If p up to and including i is a valid permutation
        int max = 0;
        for (int i = 0; i < n; i++) {
            max = std::max(p[i], max);
            if (max == i + 1) {
                pos[i] = true;
            } else {
                pos[i] = false;
            }
        }

        // Finding invalid LR borders
        unordered_set<int> invalid_borders;
        for (int i = 0; i < n - 1; i++) {
            if (s[i] == 'L' && s[i + 1] == 'R') {
                if (!pos[i]) {
                    invalid_borders.insert(i);
                }
            }
        }

        // Gathering queries
        int queries[q];
        for (auto& x : queries) {
            cin >> x;
        }

        // Processing queries
        for (auto x : queries) {
            x--;  // x is an index

            // Change the string s
            if (s[x] == 'L') {
                s[x] = 'R';
            } else {
                s[x] = 'L';
            }

            // Modify invalid_borders
            if (s[x - 1] == 'L' && s[x] == 'R') {
                if (!pos[x - 1]) {
                    invalid_borders.insert(x - 1);
                }
            } else {
                if (invalid_borders.count(x - 1)) {
                    invalid_borders.erase(x - 1);
                }
            }
            if (s[x] == 'L' && s[x + 1] == 'R') {
                if (!pos[x]) {
                    invalid_borders.insert(x);
                }
            } else {
                if (invalid_borders.count(x)) {
                    invalid_borders.erase(x);
                }
            }

            cout << (invalid_borders.empty() ? "YES" : "NO") << endl;
        }
    }
}