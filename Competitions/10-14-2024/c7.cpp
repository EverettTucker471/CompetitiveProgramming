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

void c7() {
    int _;
    cin >> _;

    while (_--) {
        int n, k;
        cin >> n >> k;

        map<int, int> map;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            map[x]++;
        }

        int rtn = 0;
        int count = 0; // Number of items in the window
        int size = 0; // Size of the window
        int prev = -1;
        for (auto x : map) {
            if (x.first - prev > 1) {
                count = x.second;
                size = 1;
            } else {
                count += x.second;
                size++;
                if (size > k) {
                    count -= map[x.first - k];
                    size--;
                }
            }
            prev = x.first;
            rtn = std::max(rtn, count);
        }
        cout << rtn << endl;
    }
}