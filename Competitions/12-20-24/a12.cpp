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

void a12() {
    // Count continuous strings of non-zero

    int _;
    cin >> _;

    while (_--) {
        int n;
        cin >> n;
        int a[n];
        for (auto& x : a) {cin >> x;}

        int count = 0;
        int cur = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] == 0) {
                if (cur > 0) {
                    count++;
                    cur = 0;
                }
            } else {
                cur += 1;
            }
        }

        if (cur > 0) {
            count++;
        }

        cout << (count > 1 ? 2 : count) << endl;
    }
}