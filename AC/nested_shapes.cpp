#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    string s;
    cin >> n;
    cin >> s;

    char type;
    cin >> type;

    double side;  // Side length for diamond and square, radius for circle
    double quant;  // Either perimeter or area
    cin >> quant;
    if (type == 'A') {
        if (s[0] == 'C') {
            side = sqrt(quant / M_PI);
        } else {
            side = sqrt(quant);
        }
    } else {
        if (s[0] == 'C') {
            side = quant / (2 * M_PI);
        } else {
            side = quant / 4;
        }
    }

    char compute;
    cin >> compute;

    for (int i = 1; i < n; i++) {
        if (s[i - 1] == 'C') {
            side *= sqrt(2);
        } else if (s[i - 1] == 'S') {
            if (s[i] == 'C') {
                side /= 2;
            } else if (s[i] == 'D') {
                side *= sqrt(2) / 2;
            }
        } else if (s[i - 1] == 'D') {
            if (s[i] == 'C') {
                side /= 2;
            } else if (s[i] == 'S') {
                side *= sqrt(2) / 2;
            }
        }
    }

    double rtn;
    if (compute == 'A') {
        if (s[n - 1] == 'C') {
            rtn = M_PI * side * side;
        } else {
            rtn = side * side;
        }
    } else {
        if (s[n - 1] == 'C') {
            rtn = 2 * M_PI * side;
        } else {
            rtn = 4 * side;
        }
    }

    printf("%.8lf\n", rtn);
}