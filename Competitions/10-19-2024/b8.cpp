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

void b8() {
    int _;
    cin >> _;

    while (_--) {
        int n;
        cin >> n;
        string rtn = "1";
        for (int i = 0; i < n - 1; i++) {
            rtn += '0';
        }
        cout << rtn << endl;
    }
}