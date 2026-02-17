#include <bits/stdc++.h>

using namespace std;

int main() {
    int _;
    cin >> _;

    while (_--) {
        int n, l, d, g;
        cin >> n >> l >> d >> g;

        // Compute the area of the base polygon
        
        double radius = (double) l / (2 * sin(M_PI / n));

        double area = 0.5 * n * radius * radius * sin(2 * M_PI / n);
        double expansion = d * g;

        area += n * l * expansion;  // rectanges
        area += M_PI * expansion * expansion;

        printf("%.8lf\n", area);
    }
}