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

void bootstrap() {
    long long int n;
    cin >> n;

    double left = 0;
    double right = 11;
    while (right - left > 0.0000001) {
        double mid = left / 2 + right / 2;

        if (std::pow(mid, mid) > n) {
            right = mid;
        } else {
            left = mid;
        }
    }

    printf("%.8lf\n", left);
}