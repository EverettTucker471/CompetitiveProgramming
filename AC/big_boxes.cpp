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

bool checkBoxes(const vector<int>& w, int n, int k, int max_weight) {
    int box = 0;
    int num_boxes = 0;
    for (int i = 0; i < n; i++) {
        if (box + w[i] <= max_weight) {
            box += w[i];
        } else {
            box = 0;
            num_boxes++;
            i--;
        }
    }

    // Incrementing num_boxes is expected, so compensate with strict inequality
    return num_boxes < k;
}

void big_boxes() {
    int n, k;
    cin >> n >> k;
    vector<int> w(n);
    for (auto& x : w) cin >> x;

    // Binary search for the weight, and then greedy optimization
    int left = *std::max_element(w.begin(), w.end());
    int right = std::accumulate(w.begin(), w.end(), 0);

    while (left < right) {
        int mid = left / 2 + right / 2;

        if (checkBoxes(w, n, k, mid)) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }

    cout << left << endl;
}