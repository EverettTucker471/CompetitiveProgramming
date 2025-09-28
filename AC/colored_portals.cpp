#include <iostream>
#include <vector>

using namespace std;

/*
 * The path is at most of length 2, if the colors are mutually exclusive
 * In this case, we need to find a city with different portals between them,
 * or determine that there is none
 * We cannot precompute distances, q should be O(logn)
 * Complementary Pairs
 * 0-5
 * 1-4
 * 2-3
 */

const vector<string> types = {"BG", "BR", "BY", "GR", "GY", "RY"};

int search(int x, int y, const vector<int>& a) {
    int left = 0;
    int right = a.size() - 1;

    while (left < right - 1) {
        int mid = (left + right) / 2;
        if (a[mid] < x) {
            left = mid;
        } else if (a[mid] > y) {
            right = mid;
        } else {
            return 0;
        }
    }
    if ((x < a[left] && a[left] < y) || (x < a[right] && a[right] < y)) {
        return 0;
    }
    return min(min(abs(x - a[left]), abs(x - a[right])), min(abs(a[right] - y), abs(a[left] - y)));
}

void colored_portals() {
    int _;
    cin >> _;

    while (_--) {
        int n, q;
        cin >> n >> q;

        vector<vector<int>> sorted(6);
        vector<int> portals(n);
        for (int i = 0; i < n; i++) {
            string s;
            cin >> s;
            for (int j = 0; j < 6; j++) {
                if (s == types[j]) {
                    portals[i] = j;
                    sorted[j].push_back(i);
                    break;
                }
            }
        }

        while (q--) {
            int x, y;
            cin >> x >> y;
            x--;
            y--;
            if (x > y) {
                int temp = y;
                y = x;
                x = temp;
            }

            if (portals[x] + portals[y] == 5) {
                // Complementary pair --> length 2 path
                // Run 4 binary searches for the final answer
                // Each searchDFS should return the number closest to the interval desired -> (x, y)
                int rtn = INT_MAX;
                for (int i = 0; i < 6; i++) {
                    if (i != portals[x] && i != portals[y] && !sorted[i].empty()) {
                        rtn = std::min(rtn, search(x, y, sorted[i]));
                    }
                }
                cout << ((rtn == INT_MAX) ? -1 : 2 * rtn + abs(x - y)) << endl;
            } else {
                cout << abs(x - y) << endl;
            }
        }
    }
}