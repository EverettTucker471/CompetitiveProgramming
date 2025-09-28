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

void c8() {
    int _;
    cin >> _;

    while (_--) {
        int n;
        cin >> n;
        string a;
        cin >> a;

        bool rtn = false;
        if (a[0] == '1' || a[n - 1] == '1') {
            rtn = true;
        } else {
            for (int i = 0; i < n - 1; i++) {
                if (a[i] == '1' && a[i + 1] == '1') {
                    rtn = true;
                    break;
                }
            }
        }

        cout << (rtn ? "YES" : "NO") << endl;
    }
}