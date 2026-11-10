#include <bits/stdc++.h>

using namespace std;

int main() {
    double d, s, e;
    cin >> d >> s >> e;

    // Probability of an original door (1 / d) * s
    // Probability of a swap door (1 - s / d) / (d - s - e)

    double swap_doors = min(d - s - e, s);
    double orig_doors = s - swap_doors;

    double rtn = swap_doors * (1 - s / d) / (d - s - e) + orig_doors * (1 / d);
    printf("%.8lf\n", rtn);
}