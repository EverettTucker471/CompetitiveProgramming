#include <iostream>
#include <vector>
using namespace std;

pair<int, int> getMaxMin(const int a[], int n) {
    int max = a[0];
    int min = a[0];
    for (int i = 1; i < n; i++) {
        max = std::max(max, a[i]);
        min = std::min(min, a[i]);
    }
    return {max, min};
}

void absolute_zero() {
    int _;
    cin >> _;

    while (_--) {
        int n;
        cin >> n;
        int a[n];
        for (auto& x : a) {cin >> x;}

        vector<int> moves;
        int k = 0;
        while (k < 40) {
            pair<int, int> max_min = getMaxMin(a, n);
            if (max_min.first == 0 && max_min.second == 0) {
                break;
            } else if (max_min.first == max_min.second) {
                moves.push_back(max_min.first);
                k++;
                break;
            } else {
                int x = (max_min.first + max_min.second) / 2;
                moves.push_back(x);
                for (auto& num : a) {
                    num = std::abs(num - x);
                }
                k++;
            }
        }
        if (k == 40) {
            cout << -1 << endl;
        } else {
            cout << k << endl;
            for (auto x: moves) { cout << x << " "; }
            cout << endl;
        }
    }
}