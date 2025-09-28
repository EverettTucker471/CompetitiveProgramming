#include <iostream>

// Answer btw is 27/512

double p(int i, int n) {
    if (n == 0) {
        if (i == 6) {
            return 1;
        } else {
            return 0;
        }
    }

    if (i == 1) {
        return p(2, n - 1) / 2;
    } else if (i == 11) {
        return p(10, n - 1) / 2;
    } else {
        return p(i - 1, n - 1) / 2 + p(i + 1, n - 1) / 2;
    }
}
