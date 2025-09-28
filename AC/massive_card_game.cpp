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

int findRange(const int cards[], int n, int l, int r) {
    if (l > cards[n - 1] || r < cards[0]) return 0;  // Interval out of bounds
    r = min(r, cards[n - 1]);
    l = max(l, cards[0]);

    // Finding the left index
    int left = 0;
    int right = n - 1;
    while (left < right) {
        int mid = (left + right + 1) / 2;

        if (cards[mid] >= l) {
            right = mid - 1;
        } else {
            left = mid;
        }
    }

    int lower = left;
    left = 0;
    right = n - 1;
    while (left < right) {
        int mid = (left + right) / 2;
        if (cards[mid] <= r) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }

    int upper = left;
    // cout << "Upper|Lower " << upper << "|" << lower << endl;
    int rtn = upper - lower - 1;
    if (cards[lower] == l) rtn++;
    if (cards[upper] == r) rtn++;

    return rtn;
}

void massive_card_game() {
    int n;
    cin >> n;
    int cards[n];
    for (auto& x : cards) cin >> x;

    // Just two binary searches for indices in a sorted list
    std::sort(cards, cards + n);

    int q;
    cin >> q;
    vector<pair<int, int>> queries(q);
    for (auto& x : queries) {
        cin >> x.first;
        cin >> x.second;
    }

    for (auto x : queries) {
        cout << findRange(cards, n, x.first, x.second) << endl;
    }
}