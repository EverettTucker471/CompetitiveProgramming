#include <iostream>
#include <algorithm>

void MaximumSum() {
    int iterations;
    std::cin >> iterations;

    for (int iteration = 0; iteration < iterations; iteration++) {
        int n, k;
        std::cin >> n >> k;
        int arr[n];

        for (int& x : arr) {
            std::cin >> x;
        }

        std::sort(arr, arr + n);

        int a = 0;
        int b = 1;
        int c = n - 1;
        for (int i = 0; i < k; i++) {
            if (arr[a] + arr[b] < arr[c]) {
                a += 2;
                b += 2;
            } else {
                c--;
            }
        }

        long long int rtn = 0;
        for (; a <= c; a++) {
            rtn += arr[a];
        }

        std::cout << rtn << std::endl;
    }
}

int main() {
    MaximumSum();
    return 0;
}
