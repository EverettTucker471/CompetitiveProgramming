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

void d21() {
    int _;
    cin >> _;

    while (_--) {
        int n;
        cin >> n;
        vector<int> odds;
        long long int even_sum = 0;

        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            if (x % 2) {
                odds.push_back(x);
            } else {
                even_sum += x;
            }
        }

        // Want to alternate odd/even sorted decreasing
        sort(odds.begin(), odds.end(), std::greater<>());
        long long int rtn = 0;
        if (odds.empty()) {
            cout << 0 << endl;
        } else {
            rtn += odds[0];
            rtn += even_sum;
            int i = 1;
            odds.pop_back();  // Turning lawnmower off
            while (i < odds.size()) {
                rtn += odds[i++];
                odds.pop_back();
            }
            cout << rtn << endl;
        }
    }
}