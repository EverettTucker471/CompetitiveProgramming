#include <iostream>
#include <vector>
#include <string>
using namespace std;

void sheldon_and_ice_pieces() {
    int t;
    cin >> t;
    string a;
    cin >> a;

    vector<int> want(10, 0);
    while (t > 0) {
        want[t % 10]++;
        t /= 10;
    }
    vector<int> have(10, 0);
    for (char x : a) {
        have[x - '0']++;
    }

    int rtn = INT_MAX;
    for (int i = 0; i < 10; i++) {
        if (want[i] > 0) {
            if (i == 2 || i == 5) {
                rtn = min(rtn, (have[2] + have[5]) / (want[2] + want[5]));
            } else if (i == 6 || i == 9) {
                rtn = min(rtn, (have[6] + have[9]) / (want[6] + want[9]));
            } else {
                rtn = min(rtn, have[i] / want[i]);
            }
        }
    }
    cout << rtn;
}