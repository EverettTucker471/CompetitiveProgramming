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

void inflation() {
    // Sorting and two-pointer
    int n;
    cin >> n;
    int a[n];
    for (auto& x : a) cin >> x;

    std::sort(a, a + n);

    bool impossible = false;
    double rtn = 1.0;
    for (int i = 0; i < n; i++) {
        if (a[i] > i + 1) {
            impossible = true;
            break;
        }
        rtn = min(rtn, (double) a[i] / (i + 1));
    }

    if (impossible) {
        cout << "impossible" << endl;
    } else {
        cout << rtn << endl;
    }
}