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

void b10() {
    long long int s;
    cin >> s;

    // This is r^2
    int left = 1;
    int right = 1000000000;

    while (left < right) {
        int mid = (left + right) / 2;
        long long int rtn = 0;
        for (int i = 1; i < sqrt(mid); i++) {
            rtn += floor(sqrt(mid - i * i));
        }
        rtn *= 4;

        if (rtn > s) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }

    printf("%.8f", sqrt(left));
}