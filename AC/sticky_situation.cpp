#include<vector>
#include<iostream>
#include<unordered_map>
#include<map>
#include<unordered_set>
#include<set>
#include<cmath>
#include <algorithm>

using namespace std;

void sticky_situation() {
    int n;
    cin >> n;
    vector<long long> a(n);
    for (auto& x : a) cin >> x;

    sort(a.begin(), a.end());

    bool rtn = false;
    for (int i = 0; i < n - 2; i++) {
        if (a[i] + a[i + 1] > a[i + 2]) {
            rtn = true;
            break;
        }
    }

    cout << (rtn ? "possible" : "impossible") << endl;
}