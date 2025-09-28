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

double CoM(double x, int h, int a, int w) {
    return 0.5 * (x * x * w + h * h * a - x * x * a) / (x * w + h * a - x * a);
}

void a10() {
    int h, r, a, w;
    cin >> h >> r >> a >> w;

    double left = 0;
    double right = h;

    while (right - left > 0.000000001) {
        double m1 = (2 * left + right) / 3;
        double m2 = (left + 2 * right) / 3;

        double v1 = CoM(m1, h, a, w);
        double v2 = CoM(m2, h, a, w);

        if (v1 < v2) {
            right = m2;
        } else {
            left = m1;
        }
    }

    printf("%.8f", (left + right) / 2);
    cout << endl;
}
