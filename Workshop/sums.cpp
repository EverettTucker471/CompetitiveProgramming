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

/*
 * Check for a difference in triangular numbers
 */

void sums() {
    int _;
    cin >> _;

    while (_--) {
        int n;
        cin >> n;

        bool found = false;
        int length;
        int mid;
        for (length = 2; (length * (length + 1)) / 2 <= n; length++) {
            if (length % 2 == 1 && n % length == 0) {
                // Determine if it's long enough
                mid = n / length;
                if (mid > length / 2) {
                    found = true;
                    break;
                }
            } else if (length % 2 == 0 && n % length == length / 2) {
                mid = (n - length / 2) / length;
                if (mid >= length / 2) {
                    found = true;
                    break;
                }
            }
        }

        if (found) {
            cout << n << " = ";
            for (int i = mid - (length - 1) / 2; i < mid + length / 2; i++) {
                cout << i << " + ";
            }
            cout << mid + length / 2 << endl;
        } else {
            cout << "IMPOSSIBLE" << endl;
        }
    }
}