#include<vector>
#include<iostream>
#include<unordered_map>
#include<map>
#include<unordered_set>
#include<set>
#include<cmath>
#include<climits>
#include <algorithm>

using namespace std;

void b6() {
    int _;
    cin >> _;

    while (_--) {
        int n, x;
        cin >> n >> x;
        int a[n];
        for (auto& k : a) {
            cin >> k;
        }

        // Sorting the numbers descending
        sort(a, a + n, std::greater<>());

        vector<unsigned long long int> heap(x, 0);
        for (int i = 0; i < n; i++) {
            std::make_heap(heap.begin(), heap.end(), std::greater<>());
            heap.front() += a[i];
        }

        // Return max element in the heap
        std::make_heap(heap.begin(), heap.end());
        cout << heap.front() << endl;
    }
}

void b6_new() {
    int _;
    cin >> _;

    while (_--) {
        int n, x;
        cin >> n >> x;
        int a[n];
        for (auto &k: a) {
            cin >> k;
        }

        unsigned long long int rtn = 0;
        bool flag = true;
        while (flag) {
            std::sort(a, a + n, std::greater<>());
            int block = x - 1;
            flag = false;
            while (block < n && a[block] > 0) {
                flag = true;
                rtn += a[block];
                for (int i = block - x + 1; i <= block; i++) {
                    a[i] -= a[block];
                }
                block += x;
            }
            /*
            for (auto k : a) {
                cout << k << " ";
            }
            cout << endl;
             */
        }

        cout << rtn + a[0] << endl;
    }
}

void b6_simple() {
    int _;
    cin >> _;

    while (_--) {
        int n, x;
        cin >> n >> x;
        int a[n];
        unsigned long long int max = 0;
        unsigned long long sum = 0;
        for (auto &k: a) {
            cin >> k;
            max = std::max(max, (unsigned long long int) k);
            sum += k;
        }

        unsigned long long int dividend;
        if (sum % x == 0) {
            dividend = sum / x;
        } else {
            dividend = sum / x + 1;
        }
        cout << std::max(max, dividend) << endl;


    }
}