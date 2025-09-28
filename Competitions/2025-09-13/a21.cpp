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

void a21() {
    int _;
    cin >> _;

    while (_--) {
        int x, n;
        cin >> x >> n;

        if (n % 2) {
            cout << x << endl;
        } else {
            cout << 0 << endl;
        }
    }
}