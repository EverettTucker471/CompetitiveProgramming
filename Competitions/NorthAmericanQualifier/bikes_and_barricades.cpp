#include <iostream>
#include <vector>
#include <climits>

using namespace std;

void bikes_and_barricades() {
    int n;
    cin >> n;
    double rtn = INT_MAX;

    while (n--) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        if (x2 - x1 != 0) {
            if ((x2 <= 0 && x1 >= 0) || (x2 >= 0 && x1 <= 0)) {
                double intercept = y1 - ((double) y2 - y1) / (x2 - x1) * x1;
                if (intercept > 0) {
                    rtn = std::min(rtn, intercept);
                }
            }
        }
    }

    cout << (rtn == INT_MAX ? -1 : rtn);
}

