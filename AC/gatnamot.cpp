#include <bits/stdc++.h>

using namespace std;

int main() {
    // Compute lattice points inside circle of radius r

    int r;
    cin >> r;

    // Compute quarters
    long rtn = 0;
    for (long x = 1; x <= r; x++) {
        // Compute the height of the circle at x
        rtn += (long) sqrt((double) r * r - x * x) + 1;
    }

    cout << rtn * 4 + 1 << endl;
}