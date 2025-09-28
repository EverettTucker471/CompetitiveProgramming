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

void a11() {
    int n;
    cin >> n;

    vector<int> divisors(n, 2);
    divisors[0] = 1;
    for (int d = 2; d <= n / 2; d++) {
        int k = 2 * d - 1;
        while (k <= n) {
            divisors[k]++;
            k += d;
        }
    }

    for (auto x : divisors) {
        cout << x << '\n';
    }
}