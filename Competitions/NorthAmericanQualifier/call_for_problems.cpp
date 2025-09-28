#include <iostream>
#include <vector>
#include <climits>

using namespace std;

void call_for_problems() {
    int n;
    cin >> n;

    int rtn = 0;
    while (n--) {
        int r;
        cin >> r;
        rtn += r % 2;
    }

    cout << rtn;
}
