#include <iostream>
#include <algorithm>

void everything_nim() {
    int _;
    std::cin >> _;

    while (_--) {
        int n;
        std::cin >> n;
        int arr[n];
        for (auto& x : arr) {std::cin >> x;}
        std::sort(arr, arr + n);


        if (arr[0] > 1) {std::cout << "Alice" << std::endl; continue;}
        bool turn = false;
        bool rtn = true;
        for (int i = 1; i < n; i++) {
            if (arr[i] == arr[i - 1] + 1) {
                turn = !turn;
            } else if (arr[i] > arr[i - 1] + 1) {
                std::cout << (turn ? "Alice" : "Bob") << std::endl;
                rtn = false;
                break;
            }
        }

        if (rtn) {std::cout << (turn ? "Bob" : "Alice") << std::endl;}
    }
}