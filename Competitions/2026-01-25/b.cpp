#include <bits/stdc++.h>

using namespace std;

void swap(int i, int j, int a[]) {
    int temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}

int main() {
    int _;
    cin >> _;

    while (_--) {
        int n;
        cin >> n;
        int a[n];
        for (auto& x : a) cin >> x;

        int left = n - 1;
        int right = 0;

        // Left Bound
        for (int i = 0; i < n; i++) {
            if (a[i] < n - i) {
                left = i;
                break;
            }
        }

        // Right bound
        int max = INT_MIN;
        for (int i = left + 1; i < n; i++) {
            if (a[i] > max) {
                right = i;
                max = a[i];
            }
        }

        // Swap 0 and max index
        while (left < right) {
            swap(left, right, a);
            left++;
            right--;
        }

        for (auto x : a) {
            cout << x << " ";
        }
        cout << "\n";
    }
}