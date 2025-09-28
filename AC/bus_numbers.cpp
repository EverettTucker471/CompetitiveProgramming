#include<vector>
#include<iostream>
#include<unordered_map>
#include<map>
#include<unordered_set>
#include<set>
#include<cmath>
#include <algorithm>
#include <climits>

using namespace std;

void bus_numbers() {
    int n;
    cin >> n;
    int a[n];
    for (auto& x : a) cin >> x;

    std::sort(a, a + n);

    int row_count = false;
    cout << a[0];
    for (int i = 1; i < n; i++) {
        while (a[i] == a[i - 1] + 1) {
            row_count++;
            i++;
        }

        if (row_count > 1) {
            cout << "-" << a[i - 1];
            i--;
        } else if (row_count == 1) {
            if (i == n) {
                cout << " " << a[i - 1];
                break;
            }
            cout << " " << a[i - 1] << " " << a[i];
        } else {
            cout << " " << a[i];
        }
        row_count = 0;
    }
}