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

void a9() {
    int _;
    cin >> _;

    while (_--) {
        int n;
        cin >> n;
        int a[n];
        for (auto& x : a) {
            cin >> x;
        }
        int rtn = true;
        for (int i = 0; i < n - 1; i++) {
            if (std::abs(a[i] - a[i + 1]) != 5 && std::abs(a[i] - a[i + 1]) != 7) {
                rtn = false;
                break;
            }
        }

        cout << (rtn ? "YES" : "NO") << endl;
    }
}