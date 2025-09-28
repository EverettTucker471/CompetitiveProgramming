#include<vector>
#include<iostream>
#include<unordered_map>
#include<map>
#include<unordered_set>
#include<set>
#include<cmath>
#include<climits>
#include <algorithm>

using namespace std;

void d7() {
    int n, m;
    cin >> n >> m;
    int r[n];
    for (auto& x : r) {cin >> x;}

    int free_points = 0;
    // Strength, Intelligence
    pair<int, int> state = {0, 0};
    int rtn = 0;

    for (int i = 0; i < n; i++) {
        if (r[i] == 0) {
            free_points++;
        } else if (r[i] < 0) {
            // Strength Check
            int nec = std::max(std::abs(r[i]) - state.first, 0);
            if (nec <= free_points) {
                state.first += nec;
                free_points -= nec;
                rtn++;
            } else {
                break;
            }
        } else {
            // Intelligence Check
            int nec = std::max(r[i] - state.second, 0);
            if (nec <= free_points) {
                state.second += nec;
                free_points -= nec;
                rtn++;
            } else {
                break;
            }
        }
        cout << "Points: " << free_points << " : " << state.first << " " << state.second << endl;
    }

    cout << rtn << endl;
}