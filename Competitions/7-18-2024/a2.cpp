#include <iostream>

void a2() {
    int _;
    std::cin >> _;

    while (_--) {
        int n, m;
        std::cin >> n >> m;
        int arr[n * m];

        for (auto& x : arr) {
            std::cin >> x;
        }

        if (n == 1 && m == 1) {std::cout << "-1" << std::endl; continue;}

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                std::cout << arr[(i * m + j + 1) % (n * m)];
                if (j < m - 1) {std::cout << " ";}
            }
            if (i != n - 1 || _ != 0) {std::cout << std::endl;}
        }
    }
}
