#include <iostream>
#include <algorithm>
#include <unordered_map>

// This same approach works for both B1 and B2, the bonus because it already uses a hashmap
using namespace std;

void b3() {
    int _;
    cin >> _;

    while (_--) {
        int n;
        long long int m;
        cin >> n >> m;
        unordered_map<int, int> map;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            map[x]++;
        }

        long long int rtn = 0;
        for (auto x : map) {
            if (map.count(x.first + 1) > 0) {
                // The game plan is to fill it up with the small one, then fill the rest with large
                // Finally, convert small to large while less than m
                long long int a = min((long long int) x.second, m / x.first);
                long long int diff = m - a * x.first;
                long long int b = min((long long int) map[x.first + 1], diff / (x.first + 1));
                long long ans = a * x.first + b * (x.first + 1);
                ans += min(m - ans, map[x.first + 1] - b);
                rtn = max(rtn, ans);
            } else {
                rtn = max(rtn, x.first * min((long long int) x.second, m / x.first));
            }
        }
        cout << rtn << endl;
    }
}