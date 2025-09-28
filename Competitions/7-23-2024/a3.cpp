#include <iostream>
#include <cmath>
using namespace std;

void a3() {
    int _;
    cin >> _;

    while (_--) {
        int n, k;
        cin >> n >> k;

        int size = n;
        int rtn = 0;
        while (k > 0) {
            if (size == n) {
                k -= size;
                rtn++;
            } else {
                k -= size;
                rtn++;
                if (k <= 0) {
                    break;
                }
                k -= size;
                rtn++;
            }
            size--;
        }
        cout << rtn << endl;
    }
}
