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

void c13() {
    int _;
    cin >> _;

    while (_--) {
        int n;
        cin >> n;
        int b[2 * n];
        for (auto& x : b) {cin >> x;}

        // Make a_1 the largest possible element
        std::sort(b, b + 2 * n);

        long a = 0;
        long res[2 * n];
        int left = 0;
        int right = 2 * n - 1;
        for (int i = 0; i < 2 * n; i++) {
            if (i % 2) {
                a -= b[left];
                res[i] = b[left];
                left++;
            } else {
                a += b[right];
                res[i] = b[right];
                right--;
            }
        }

        if (a == res[0]) {
            long temp = res[2 * n - 1];
            res[2 * n - 1] = res[2 * n - 2];
            res[2 * n - 2] = temp;
            a -= 2 * (res[2 * n - 1] - res[2 * n - 2]);
        }

        if (a <= res[0]) {
            long temp = a;
            a = res[0];
            res[0] = temp;
            res[0] += 2 * (a - res[0]);
        }

        cout << a << " ";
        for (auto x : res) {cout << x << " ";}
        cout << endl;
    }
}

void c13b() {
    int _;
    cin >> _;

    while (_--) {
        int n;
        cin >> n;
        int b[2 * n];
        unordered_set<int> set;
        for (auto& x : b) {cin >> x;}
        for (auto x : b) {set.insert(x);}

        // Computing initial partials
        long a = 0;
        for (int i = 0; i < 2 * n; i += 2) {
            a += b[i];
            a -= b[i + 1];
        }

        // Swapping every pair
        if (a < 0) {
            for (int i = 0; i < 2 * n; i += 2) {
                int temp = b[i];
                b[i] = b[i + 1];
                b[i + 1] = temp;
            }
            a *= -1;
        }

        if (a > 0 && !set.count(a)) {
            cout << a << " ";
            for (auto x : b) {cout << x << " ";}
            cout << endl;
            continue;
        }

        for (int i = 0; i < 2 * n; i += 2) {
            long a_new = a - 2 * (b[i] - b[i + 1]);

            if (a_new > 0 && !set.count(a_new)) {
                int temp = b[i];
                b[i] = b[i + 1];
                b[i + 1] = temp;
                a = a_new;
                break;
            }
        }

        cout << a << " ";
        for (auto x : b) {cout << x << " ";}
        cout << endl;
    }
}