#include <iostream>
#include <vector>
#include <climits>
#include <unordered_map>
#include <algorithm>
#include <cmath>

using namespace std;

void gears_and_axles() {
    int n;
    cin >> n;

    unordered_map<int, vector<int>> gears;

    while (n--) {
        int s, c;
        cin >> s >> c;
        gears[s].push_back(c);
    }

    for (auto& x : gears) {
        std::sort(x.second.begin(), x.second.end());
    }

    // Add their logarithms
    long double rtn = 0;
    for (auto x : gears) {
        int left = 0;
        int right = x.second.size() - 1;

        while (left < right) {
            rtn += std::log((double) x.second[right] / x.second[left]);
            left++;
            right--;
        }
    }

    printf("%Lf15", rtn);
    //cout << rtn;
    /*

    for (auto x : gears) {
        cout << x.first << " : ";
        for (auto y : x.second) {
            cout << y << " ";
        }
        cout << endl;
    }
     */
}