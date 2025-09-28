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

void c21() {
    int _;
    cin >> _;

    while (_--) {
        int n, m;
        cin >> n >> m;

        int a[n];
        int b[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i] >> b[i];
        }

        int time = 0;
        bool side = false;
        int rtn = 0;
        for (int i = 0; i < n; i++) {
            if (side != b[i]) {
                // Go to the other side
                side = !side;
                time++;
                rtn++;
            }

            rtn += 2 * ((a[i] - time) / 2);
            time = a[i];
            side = b[i];
        }

        // Final lap
        rtn += m - time;

        cout << rtn << endl;
    }
}