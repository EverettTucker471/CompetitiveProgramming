#include <iostream>
#include <vector>
using namespace std;

void a5() {
    int _;
    cin >> _;

    while (_--) {
        int n;
        cin >> n;
        int arr[n];
        for (auto& x : arr) {cin >> x;}

        int rtn = 0;
        for (int i = 0; i < n; i++) {
            rtn = std::max(rtn, arr[i] + i / 2 + (n - i - 1) / 2 + 1);
        }

        cout << rtn << endl;
    }
}