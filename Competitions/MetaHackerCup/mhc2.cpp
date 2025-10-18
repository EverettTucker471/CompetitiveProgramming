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

bool checkLadder(const vector<int>& a, int len, int n) {
    vector<bool> explored(n, false);

    vector<int> queue;
    for (int i = 0; i < n; i++) {
        if (a[i] <= len) {
            queue.push_back(i);
            explored[i] = true;
        }
    }

    while (!queue.empty()) {
        int i = queue.back();
        queue.pop_back();

        if (i > 0 && abs(a[i - 1] - a[i]) <= len && !explored[i - 1]) {
            explored[i - 1] = true;
            queue.push_back(i - 1);
        }
        if (i < n - 1 && abs(a[i] - a[i + 1]) <= len && !explored[i + 1]) {
            explored[i + 1] = true;
            queue.push_back(i + 1);
        }
    }

    for (bool x : explored) {
        if (!x) return false;
    }
    return true;
}

void mhc2() {
    int _;
    cin >> _;

    for (int c = 0; c < _; c++) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (auto& x : a) cin >> x;

        int left = 0;
        int right = 1e9;

        while (left < right) {
            int mid = (left + right) / 2;

            if (checkLadder(a, mid, n)) {
                // cout << "Mid: " << mid << '\n';
                right = mid;
            } else {
                left = mid + 1;
            }
        }

        printf("Case #%d: %d\n", c + 1, left);
    }
}

int main() {
    mhc2();
    return 0;
}