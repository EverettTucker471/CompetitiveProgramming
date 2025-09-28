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

void a8() {
    int _;
    cin >> _;

    while (_--) {
        int n;
        cin >> n;
        int min = INT_MAX;
        int max = INT_MIN;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            min = std::min(min, x);
            max = std::max(max, x);
        }

        cout << (n - 1) * (max - min) << endl;
    }
}