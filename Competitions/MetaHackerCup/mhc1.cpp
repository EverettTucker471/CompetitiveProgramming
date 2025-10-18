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

void mhc1() {
    int _;
    cin >> _;

    for (int c = 0; c < _; c++) {
        int n;
        cin >> n;
        int a[n];
        for (auto& x : a) cin >> x;

        int max = 0;
        for (int i = 0; i < n - 1; i++) {
            max = std::max(abs(a[i] - a[i + 1]), max);
        }

        printf("Case #%d: %d\n", c + 1, max);
    }
}

int main() {
    mhc1();
    return 0;
}