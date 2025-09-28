#include <iostream>
using namespace std;

// Accepted to both the easy and hard versions, Ternary Search!

void ruler() {
    int _;
    cin >> _;

    while (_--) {
        int left = 2;
        int right = 999;

        while (left <= right) {
            int m1 = (right - left) / 3 + left;
            int m2 = 2 * (right - left + 1) / 3 + left;
            if (m1 == m2) {left = m1; break;}
            cout << "? " << m1 << " " << m2 << endl;
            cout.flush();
            int a;
            cin >> a;

            if (a == m1 * m2) {
                // both smaller
                left = m2 + 1;
            } else if (a == m1 * (m2 + 1)) {
                left = m1 + 1;
                right = m2;
            } else if (a == (m1 + 1) * (m2 + 1)) {
                right = m1;
            }
        }

        cout << "! " << left << endl;
    }
}