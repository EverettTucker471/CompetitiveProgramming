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

void c12() {
    int _;
    cin >> _;

    while (_--) {
        int n, x, y;
        cin >> n >> x >> y;

        bool edge = y - x > 1 && y - x < n - 1;

        int rtn[n];
        if (n % 2) {
            rtn[0] = 2;
            for (int i = 1; i < n; i++) {
                rtn[i] = i % 2;
            }

            if (edge && rtn[x - 1] == rtn[y - 1]) {
                // Change the one farther from the 2, to a 2
                if (x - 2 > n - y) {
                    rtn[x - 1] = 2;
                } else {
                    rtn[y - 1] = 2;
                }
            }
        } else {
            // Instantiate basic alternating
            for (int i = 0; i < n; i++) {
                rtn[i] = i % 2;
            }

            // Change one to a two if different
            if (edge && rtn[x - 1] == rtn[y - 1]) {
                rtn[x - 1] = 2;
            }
        }

        for (auto z : rtn) {
            cout << z << " ";
        }
        cout << endl;
    }
}
