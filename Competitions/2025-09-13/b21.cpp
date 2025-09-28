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

void b21() {
    int _;
    cin >> _;

    while (_--) {
        int n, m, x, y;
        cin >> n >> m >> x >> y;
        int a[n];
        int b[m];
        for (auto& z : a) cin >> z;
        for (auto& z : b) cin >> z;

        int rtn = 0;
        for (auto z: a) {
            if (z < y) rtn++;
        }
        for (auto z : b) {
            if (z < x) rtn++;
        }

        cout << rtn << endl;
    }
}