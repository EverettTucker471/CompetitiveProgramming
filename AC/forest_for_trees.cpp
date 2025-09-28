#include <bits/stdc++.h>

using namespace std;

/**
 * We require that a >= b
 */
long long euclidean_algorithm(long long a, long long b) {
    while (a % b != 0) {
        long long r = a % b;
        a = b;
        b = r;
    }
    return b;
}

void forest_for_trees() {
    long long xB, yB;
    cin >> xB >> yB;

    long long x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    // Computing the GCD of xB and yB
    long long gcd = euclidean_algorithm(xB, yB);
    pair<long long, long long> step = {xB / gcd, yB / gcd};

    pair<long long, long long> bl = {min(x1, x2), min(y1, y2)};
    pair<long long, long long> tr = {max(x1, x2), max(y1, y2)};

    // Checking before the rectangle
    long long x_times = (bl.first - 1) / step.first;
    long long y_times = (bl.second - 1) / step.second;

    // This case we have a tree blocking
    if (max(x_times, y_times) > 0) {
        if (step.first < xB && step.second < yB) {
            cout << "No" << endl;
            cout << step.first << " " << step.second << endl;
            return;
        } else {
            // No trees for sure
            cout << "Yes" << endl;
            return;
        }
    } 

    // Checking after the rectangle
    x_times = tr.first / step.first;
    y_times = tr.second / step.second;

    long long ref_x;
    long long ref_y;
    if (x_times < y_times) {
        ref_x = (x_times + 1) * step.first;
        ref_y = (x_times + 1) * step.second;
    } else {
        ref_x = (y_times + 1) * step.first;
        ref_y = (y_times + 1) * step.second;
    }

    // cout << xB << " " << yB << endl;
    // cout << ref_x << " " << ref_y << endl;

    if (ref_x < xB && ref_y < yB) {
        cout << "No" << endl;
        cout << ref_x << " " << ref_y << endl;
        return;
    }

    cout << "Yes" << endl;
}

int main() {
    forest_for_trees();
    return 0;
}
