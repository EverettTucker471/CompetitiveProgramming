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

void acm() {
    int n;
    cin >> n;
    vector<pair<int, int>> minions(n);
    for (auto& x : minions) {
        cin >> x.first;
        cin >> x.second;
    }

    std::sort(minions.begin(), minions.end());

    int rtn = 0;
    int left = 0;
    int right = 1;
    while (left < n) {
        rtn++;
        int right_most = minions[left].second;
        while (minions[right].first <= right_most) {
            right_most = std::min(right_most, minions[right].second);
            right++;
        }
        left = right;
        right++;
    }

    cout << rtn << endl;
}