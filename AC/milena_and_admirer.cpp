#include <iostream>
#include <cmath>
using namespace std;

void milena_and_admirer() {
    int _;
    cin >> _;

    while (_--) {
        int n;
        cin >> n;
        int a[n];
        for (auto& x : a) {
            cin >> x;
        }

        // Backwards traversal, and determine steps to split
        long long int rtn = 0;
        int last = a[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            int split = ceil((double) a[i] / last);
            rtn += split - 1;
            last = a[i] / split;
        }

        cout << rtn << endl;
    }
}
