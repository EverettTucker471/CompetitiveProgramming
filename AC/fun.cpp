#include <iostream>

using namespace std;

// This was a lot easier than I was making it out to be
// I thought there was a mathematical simplification, but no

void fun() {
    int _;
    cin >> _;

    while (_--) {
        int n, x;
        cin >> n >> x;

        long long int rtn = 0;
        for (int a = 1; a < n && a < x; a++) {
            for (int b = 1; a * b < n && a + b < x; b++) {
                const long long int c1 = (n - a * b) / (a + b);
                const long long int c2 = x - (a + b);
                rtn += min(c1, c2);
            }
        }
        cout << rtn << endl;
    }
}