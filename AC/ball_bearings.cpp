#include <bits/stdc++.h>

using namespace std;

bool check(double D, double d, double s, int n) {
    double side = 2 * sin(M_PI / n) * (D / 2 - d / 2);
    return d + s <= side;
}

int main() {
    int _;
    cin >> _;

    while (_--) {
        double D, d, s;
        cin >> D >> d >> s;

        int left = 1;
        int right = 10000000;

        while (left < right) {
            int mid = (left + right + 1) / 2;

            if (check(D, d, s, mid)) {
                left = mid;
            } else {
                right = mid - 1;
            }
        }

        cout << left << endl;
    }
}