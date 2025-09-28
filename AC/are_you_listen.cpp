#include<vector>
#include<iostream>
#include<unordered_map>
#include<map>
#include<unordered_set>
#include<set>
#include<cmath>
#include <algorithm>

using namespace std;

bool computeIntersections(const vector<vector<int>>& devices, const pair<int, int> loc, int r) {
    int rtn = 0;
    for (auto x : devices) {
        double dist = sqrt(pow(x[0]- loc.first, 2) + pow(x[1] - loc.second, 2));
        if (r > dist - x[2]) {
            rtn++;
            if (rtn == 3) return true;
        }
    }
    return false;
}

void are_you_listening() {
    pair<int, int> loc;
    cin >> loc.first >> loc.second;
    int n;
    cin >> n;

     vector<vector<int>> devices(n, vector<int>(3));
     for (auto& x : devices) {
         for (auto& y : x) {
             cin >> y;
         }
     }

     int left = 0;
     int right = 10000;

     while (left < right) {
         int mid = (left + right + 1) / 2;
         computeIntersections(devices, loc, mid) ? right = mid - 1 : left = mid;
     }

     cout << left << endl;
}