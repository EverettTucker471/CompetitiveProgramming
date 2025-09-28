#include<vector>
#include<iostream>
#include<unordered_map>
#include<map>
#include<unordered_set>
#include<set>
#include<cmath>
#include<climits>
#include <algorithm>

using namespace std;

void b13() {
    int _;
    cin >> _;

    while (_--) {
        int n, k;
        cin >> n >> k;

        if (k % 2) {
            for (int i = 0; i < n - 1; i++) {
                cout << n << " ";
            }
            cout << n - 1 << endl;
        } else {
            for (int i = 0; i < n - 2; i++) {
                cout << n - 1 << " ";
            }
            cout << n << " ";
            cout << n - 1 << endl;
        }
    }
}