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

void b15() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& x : a) cin >> x;

    sort(a.begin(), a.end());

    // Compare to the max
    int rtn = min(n, a[n - 1]);
    for (int i = 0; i < n; i++) {
        rtn = min(rtn, a[i] + n - i - 1);
    }

    cout << rtn << endl;
}