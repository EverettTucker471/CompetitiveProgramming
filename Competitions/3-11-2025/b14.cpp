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

void b14() {
    // We must pick x = ai + aj - 1 --> Sum - num_merges = sum - n + 1

    int _;
    cin >> _;

    while (_--) {
        int n;
        cin >> n;
        int a[n];
        long sum = 0;
        for (auto& x : a) {
            cin >> x;
            sum += x;
        }

        cout << sum - n + 1 << endl;
    }
}