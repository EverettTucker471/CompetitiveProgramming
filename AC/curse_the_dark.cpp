#include<vector>
#include<iostream>
#include<unordered_map>
#include<map>
#include<unordered_set>
#include<set>
#include<cmath>
#include <algorithm>
#include <climits>

using namespace std;

const double CANDLE_RADIUS = 8;

void curse_the_dark() {
    int _;
    cin >> _;

    for (int j = 0; j < _; j++) {
        double x, y;
        cin >> x >> y;

        bool rtn = false;
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) {
            double a, b;
            cin >> a >> b;
            if (sqrt(pow(x - a, 2) + pow(y - b, 2)) <= 8.0) {
                rtn = true;
            }
        }

        cout << (rtn ? "light a candle" : "curse the darkness") << endl;
    }
}