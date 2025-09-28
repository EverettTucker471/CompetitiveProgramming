// Binary searchDFS on the maximum value of each box

#include <iostream>
using namespace std;

bool cond(const int a[], int n, int k, int val) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        if (sum + a[i] <= val) {
            sum += a[i];
        } else if (a[i] <= val) {
            sum = a[i];
            k--;
        } else {
            return false;
        }
    }
    return k > 0;
}

void bigboxes() {
    int n, k;
    cin >> n >> k;
    int a[n];
    for (auto& x : a) {cin >> x;}


    int left = 1;
    int right = INT_MAX;

    while (left < right) {
        int mid = (left + right + 1) / 2;

        if (cond(a, n, k, mid)) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }

    cout << left << endl;
}
