//
// Created by legoe on 6/29/2024.
//

// Works on test cases, don't know why it fails.
// Why can't I seem to finish these problems off?

#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

int evenDiff(int k, std::vector<int>& arr) {
    int rtn = 0;
    std::sort(arr.begin(), arr.end());
    for (int i = 0; i < arr.size(); i += 2) {rtn += (arr[i + 1] - arr[i]) / k;}
    return rtn;
}


int oddDiff(int k, std::vector<int>& arr) {
    int n = arr.size();
    if (n == 1) {return 0;}
    std::sort(arr.begin(), arr.end());
    if (n == 3) {return std::min(arr[1] - arr[0], arr[2] - arr[1]);}

    // Now we have that n >= 5
    int l = n / 2;
    int left[l];
    int right[l];

    left[0] = arr[1] - arr[0];
    for (int i = 1; i < l; i++) {
        left[i] = left[i - 1] + arr[2 * i + 1] - arr[2 * i];
    }
    right[l - 1] = arr[n - 1] - arr[n - 2];
    for (int i = l - 2; i >= 0; i--) {
        right[i] = right[i + 1] + arr[2 * i + 2] - arr[2 * i + 1];
    }

    int rtn = std::min(left[l - 1], right[0]);
    rtn = std::min(rtn, arr[2] - arr[0] + right[1]);
    rtn = std::min(rtn, arr[n - 1] - arr[n - 3] + left[l - 2]);
    for (int i = 2; i < n - 2; i++) {
        if (i % 2) {
            rtn = std::min(rtn, arr[i + 1] - arr[i - 1] + left[i/2 - 1] + right[i/2 + 1]);
        } else {
            rtn = std::min(rtn, left[i / 2 - 1] + right[i / 2]);
        }
    }

    /*
    for (auto x : left) {
        std::cout << x << " ";
    }
    std::cout << std::endl;
    for (auto x : right) {
        std::cout << x << " ";
    }
     */

    return rtn / k;
}

void beautiful_array() {
    int _;
    std::cin >> _;

    for (; _ > 0; _--) {
        int n, k;
        std::cin >> n >> k;
        int a[n];

        for (int& x : a) {
            std::cin >> x;
        }

        std::unordered_map<int, std::vector<int>> residues;
        for (int i = 0; i < n; i++) {
            residues[a[i] % k].push_back(a[i]);
        }

        int rtn = 0;
        bool palindromic = true;
        bool works = true;
        for (auto x : residues) {
            if (x.second.size() % 2) {
                rtn += oddDiff(k, x.second);
                if (palindromic) {
                    palindromic = false;
                } else {
                    std::cout << -1 << std::endl;
                    works = false;
                    break;
                }
            } else {
                rtn += evenDiff(k, x.second);
            }
        }

        if (works) {std::cout << rtn << std::endl;}
    }
}
