#include <bits/stdc++.h>

using namespace std;

void rudolf_and_imbalance() {
    int _;
    cin >> _;

    while (_--) {
        int n, m, k;
        cin >> n >> m >> k;

        int a[n], d[m], f[k];
        for (auto& x : a) {cin >> x;}
        for (auto& x : d) {cin >> x;}
        for (auto& x : f) {cin >> x;}

        pair<int, int> interval = {0, 0};
        pair<int, int> second = {0, 0};
        for (int i = 1; i < n; i++) {
            if (a[i] - a[i - 1] > interval.second - interval.first) {
                second = interval;
                interval = {a[i - 1], a[i]};
            } else if (a[i] - a[i - 1] > second.second - second.first) {
                second = {a[i - 1], a[i]};
            }
        }

        sort(f, f + k);
        double min = ((double) interval.second - interval.first) / 2;
        double median = ((double) interval.first + interval.second) / 2;
        for (int i = 0; i < m; i++) {
            int left = 0;
            int right = k - 1;

            while (left < right - 1) {
                int mid = (left + right) / 2;

                if (f[mid] + d[i] > median) {
                    right = mid;
                } else {
                    left = mid;
                }
            }

            min = std::min(min, std::min(abs(d[i] + f[left] - median), abs(d[i] + f[right] - median)));
        }

        cout << std::max(second.second - second.first, (int) (((double) interval.second - interval.first) / 2 + min)) << endl;
    }
}
