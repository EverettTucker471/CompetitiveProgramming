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

void e21() {
    int _;
    cin >> _;

    while (_--) {
        int n, k;
        cin >> n >> k;
        int a[n];
        for (auto& x : a) cin >> x;

        unordered_map<int, int> ref_map;
        for (int x : a) ref_map[x]++;

        bool invalid = false;
        for (auto& x : ref_map) {
            if (x.second % k != 0) {
                invalid = true;
            }
            x.second /= k;
        }

        if (invalid) {
            cout << 0 << endl;
            continue;
        }

        long long int rtn = 0;
        unordered_map<int, int> sliding_map;

        int right = 0;
        for (int left = 0; left < n; left++) {
            while (right < n) {
                sliding_map[a[right]]++;
                if (sliding_map[a[right]] > ref_map[a[right]]) break;
                right++;
            }

            // Undoing the overstep
            sliding_map[a[right]]--;

            // Adding the interval
            rtn += right - left;
            // cout << "Interval: " << left << " " << right << endl;

            sliding_map[a[left]]--;
        }

        cout << rtn << endl;
    }
}