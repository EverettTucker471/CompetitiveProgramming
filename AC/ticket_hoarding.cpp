//
// Created by legoe on 7/5/2024.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

bool sortFirst(const pair<int, int>& a, const pair<int, int>& b) {return a.first < b.first;}
bool sortSecond(const pair<int, int>& a, const pair<int, int>& b) {return a.second < b.second;}

void ticket_hoarding() {
    int _;
    cin >> _;

    while (_--) {
        int n, m, k;
        cin >> n >> m >> k;
        int arr[n];
        for (auto& x : arr) {cin >> x;}
        m = std::min(m, k);

        vector<pair<int, int>> sortable;
        for (int i = 0; i < n; i++) {
            sortable.emplace_back(arr[i], i);
        }

        int l = ceil((double) k / m);
        sort(sortable.begin(), sortable.end(), sortFirst);
        sortable.resize(l);
        int max = sortable[l - 1].first;
        sort(sortable.begin(), sortable.end(), sortSecond);

        long long int rtn = 0;
        long long int cur = 0;
        for (int i = 0; i < l; i++) {
            if (sortable[i].first == max) {
                rtn += (cur + sortable[i].first) * (k % m == 0 ? m : k % m);
                cur += (k % m == 0 ? m : k % m);
                max = -1;  // Ensuring this doesn't run again
            } else {
                rtn += (cur + sortable[i].first) * m;
                cur += m;
            }
        }

        cout << rtn << endl;
    }
}