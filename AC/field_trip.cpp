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

void field_trip() {
    int _;
    cin >> _;

    while (_--) {
        int n;
        cin >> n;
        int a[n];
        for (auto& x : a) {cin >> x;}

        int left = 0;
        int right = n - 1;
        while (left < right) {
            int dist = (a[left] == a[left - 1]) + (a[right] == a[right + 1]);
            if (dist > 0) {
                int temp = a[left];
                a[left] = a[right];
                a[right] = temp;
            }
            left++;
            right--;
        }

        int rtn = 0;
        for (int i = 1; i < n; i++) {
            rtn += a[i] == a[i - 1];
        }

        cout << rtn << endl;
    }
}