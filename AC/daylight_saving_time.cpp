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

void daylight_saving_time() {
    int _;
    cin >> _;

    while (_--) {
        char c;
        cin >> c;
        int d, h, m;
        cin >> d >> h >> m;

        int time = m + 60 * h;
        if (c == 'F') {
            time += d;
        } else {
            time -= d;
        }

        // For one extra day
        time += 24 * 60;

        cout << (time / 60) % 24 << " " << time % 60 << endl;
    }
}