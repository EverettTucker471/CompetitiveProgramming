#include <bits/stdc++.h>

using namespace std;

/**
 * Checks all hatches to make sure they're inside the given circle
 */
bool check(vector<pair<int, int>> hatches, pair<int, int> center, int radius) {
    for (auto x : hatches) {
        int dist = (x.first - center.first) * (x.first - center.first) + (x.second - center.second) * (x.second - center.second);
        if (dist == 0 || dist > radius * radius) {
            return false;
        }
    }
    return true;
}

int main() {
    int _;
    cin >> _;

    while (_--) {
        int s, h;
        cin >> s >> h;
        vector<pair<int, int>> hatches(h);

        for (auto& x : hatches) {
            cin >> x.first;
            cin >> x.second;
        }

        // Exhaustive search? Yeah...
        pair<int, int> rtn = {-1, -1};
        for (int x = 1; x < s; x++) {
            for (int y = 1; y < s; y++) {
                int radius = min(min(x, s - x), min(y, s - y));
                if (rtn.first < 0 && check(hatches, {x, y}, radius)) {
                    rtn = {x, y};
                }
            }
        }

        if ( rtn.first < 0 ) {
            cout << "poodle\n";
        } else {
            cout << rtn.first << " " << rtn.second << '\n';
        }
    }
}