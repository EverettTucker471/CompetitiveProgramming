#include<vector>
#include<iostream>
#include<unordered_map>
#include<map>
#include<unordered_set>
#include<set>
#include<cmath>
#include <algorithm>
#include <climits>

using namespace std;

int computeLeft(vector<bool> a, int h) {
    int rtn = 0;
    int m = h - 1;
    while (h >= 0) {
        rtn++;

        // Making wall at closest point
        while (m >= 0) {
            if (a[m]) {
                m--;
            } else {
                a[m] = true;
                break;
            }
        }

        while (h >= 0) {
            if (!a[h]) {
                h--;
            } else {
                a[h] = false;
                break;
            }
        }

        m = min(m, h - 1);
    }

    return rtn;
}

int computeLeftLow(vector<bool> a, int h) {
    int rtn = 0;
    int m = h - 1;
    while (h >= 0) {
        rtn++;

        while (h >= 0) {
            if (!a[h]) {
                h--;
            } else {
                a[h] = false;
                break;
            }
        }

        m = min(m, h - 1);

        // Making wall at closest point
        while (m >= 0) {
            if (a[m]) {
                m--;
            } else {
                a[m] = true;
                break;
            }
        }
    }

    return rtn;
}

int computeRight(vector<bool> a, int h) {
    int n = a.size();
    int rtn = 0;
    int m = h + 1;
    while (h < n) {
        rtn++;

        while (m < n) {
            if (a[m]) {
                m++;
            } else {
                a[m] = true;
                break;
            }
        }

        while (h < n) {
            if (!a[h]) {
                h++;
            } else {
                a[h] = false;
                break;
            }
        }

        m = max(m, h + 1);
    }

    return rtn;
}

int computeRightLow(vector<bool> a, int h) {
    int n = a.size();
    int rtn = 0;
    int m = h + 1;
    while (h < n) {
        rtn++;

        while (h < n) {
            if (!a[h]) {
                h++;
            } else {
                a[h] = false;
                break;
            }
        }

        m = max(m, h + 1);

        while (m < n) {
            if (a[m]) {
                m++;
            } else {
                a[m] = true;
                break;
            }
        }
    }

    return rtn;
}

void hamid() {
    // Hamid should attack the side with fewer walls
    // Mani should build at the closest square on the side with the fewest walls

    int _;
    cin >> _;

    while (_--) {
        int n, h;
        cin >> n >> h;
        h--;  // Adjusting from 1-indexing

        vector<bool> a(n);
        for (int i = 0; i < n; i++) {
            char c;
            cin >> c;
            a[i] = c == '#';
        }

        int left = computeLeft(a, h);
        int leftLow = computeLeftLow(a, h);
        int right = computeRight(a, h);
        int rightLow = computeRightLow(a, h);
        cout << std::max(std::min(left, rightLow), std::min(right, leftLow)) << endl;
    }
}