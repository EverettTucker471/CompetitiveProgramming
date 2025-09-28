#include <iostream>
#include <cmath>

bool kills_boss(const int damage[], const int wait[], int n, long long int t, int h) {
    long long int rtn = 0;
    for (int i = 0; i < n; i++) {
        rtn += damage[i] * ceil((double) (t - 1) / wait[i]);
        if (rtn >= h) {return true;}
    }
    return false;
}

void final_boss() {
    int _;
    std::cin >> _;

    for (; _ > 0; _--) {
        int h, n;

        std::cin >> h >> n;
        int wait[n], damage[n];
        for (int i = 0; i < n; i++) {
            std::cin >> damage[i];
        }
        for (int i = 0; i < n; i++) {
            std::cin >> wait[i];
        }

        long long int left = 1;
        long long int right = 4e10;

        while (left < right) {
            long long int mid = (left + right) / 2;

            if (kills_boss(damage, wait, n, mid, h)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }

        std::cout << left - 1 << std::endl;
    }
}
