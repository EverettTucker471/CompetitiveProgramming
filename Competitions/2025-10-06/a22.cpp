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

void a22() {
    int _;
    cin >> _;

    while (_--) {
        int n;
        cin >> n;

        int ans = n % 3 ? ((n / 3) + 1) * 3 - n : 0;
        cout << ans << endl;
    }
}