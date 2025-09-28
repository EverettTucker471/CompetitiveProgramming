#include<vector>
#include<iostream>
#include<unordered_map>
#include<map>
#include<unordered_set>
#include<set>
#include<cmath>
#include <algorithm>
#include <climits>

using namespace std;

void mix_max_mex() {
    // We need to make everything equal, and nonzero

    int _;
    cin >> _;

    while (_--) {
        int n;
        cin >> n;

        int a[n];
        for (auto& x : a) {cin >> x;}

        bool rtn = true;
        for (int i = 0; i < n - 2; i++) {
            int max = std::max(a[i], std::max(a[i + 1], a[i + 2]));

            if (max >= 0) {
                for (int j = i; j < i + 3; j++) {
                    if (a[j] == -1) a[j] = max;
                    if (a[j] == 0 || a[j] != max) rtn = false;
                }
            }
        }

        cout << (rtn ? "YES" : "NO") << endl;
    }
}