#include <iostream>
#include <cmath>
#include <map>
#include <algorithm>

using namespace std;

void photoshoot_for_gorillas() {
    int _;
    cin >> _;

    while (_--) {
        int n, m, k, w;
        cin >> n >> m >> k >> w;
        int a[w];
        for (auto& x : a) {cin >> x;}

        // Find the hashmap of how many times the k-squares intersect each grid square
        map<int, int, std::greater<>> freq;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                // Horizontal
                int sum = (m - k + 1) - std::max(0, j - k + 1) - std::max(0, m - j - k);
                // Vertical
                sum *= (n - k + 1) - std::max(0, i - k + 1) - std::max(0, n - i - k);
                freq[sum]++;
            }
        }

        std::sort(a, a + w, std::greater<>());
        unsigned long long int rtn = 0;
        int index = 0;
        for (auto x : freq) {
            for (int i = 0; i < x.second; i++) {
                if (index == w) {break;}
                rtn += (unsigned long long int) a[index] * x.first;
                index++;
            }
        }
        cout << rtn << endl;
    }
}
