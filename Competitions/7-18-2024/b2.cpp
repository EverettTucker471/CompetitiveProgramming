//
// Created by legoe on 7/18/2024.
//

#include <iostream>

void b2() {
    int _;
    std::cin >> _;

    while (_--) {
        int n;
        std::cin >> n;

        std::string s;
        std::string t;

        std::cin >> s >> t;

        if (s[0] == '1') {
            std::cout << "YES" << std::endl;
        } else if (t[0] == '1') {
            std::cout << "NO" << std::endl;
        } else {
            std::cout << "YES" << std::endl;
            /*
            for (int i = 0; i < n; i++) {
                if (s[i] == '1') {
                    std::cout << "YES" << std::endl;
                    break;
                }
                if (t[i] == '1') {
                    std::cout << "NO" << std::endl;
                    break;
                }
            }
             */
        }
    }
}
