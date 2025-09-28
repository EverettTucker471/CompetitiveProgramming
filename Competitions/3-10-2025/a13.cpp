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

void a13() {
    int _;
    cin >> _;

    while (_--) {
        int n, x;
        cin >> n >> x;
        int a[n];
        int sum = 0;
        for (auto& y : a) {
            cin >> y;
            sum += y;
        }

        cout << (sum == n * x ? "YES" : "NO") << endl;
    }
}