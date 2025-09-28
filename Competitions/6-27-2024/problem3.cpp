//
// Created by legoe on 6/27/2024.
//

#include <iostream>

void problem3() {
    int _;
    std::cin >> _;

    for (; _ > 0; _--) {
        int n;
        std::cin >> n;
        int a[n], b[n];

        for (auto& x : a) {
            std::cin >> x;
        }
        for (int& x : b) {
            std::cin >> x;
        }

        int A = 0;
        int B = 0;
        int free_likes = 0;
        int free_dislikes = 0;

        for (int i = 0; i < n; i++) {
            if (a[i] == 1 && b[i] == 1) {
                free_likes++;
            } else if (a[i] == -1 && b[i] == -1) {
                free_dislikes++;
            } else {
                if (a[i] > b[i]) {
                    A += a[i];
                } else {
                    B += b[i];
                }
            }
        }

        // Yeah, just do the simple stupid way
        for (; free_likes > 0; free_likes--) {
            if (A < B) {
                A++;
            } else {
                B++;
            }
        }
        for (; free_dislikes > 0; free_dislikes--) {
            if (A < B) {
                B--;
            } else {
                A--;
            }
        }

        std::cout << std::min(A, B) << std::endl;
    }
}
