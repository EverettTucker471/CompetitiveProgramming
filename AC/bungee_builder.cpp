#include <iostream>
#include <vector>

using namespace std;

void bungee_builder() {
    int n;
    cin >> n;
    int a[n];
    for (auto& x : a) {cin >> x;}

    // Finding the max index
    int index = 0;
    int max = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] > max) {
            index = i;
            max = a[i];
        }
    }

    int rtn = 0;
    int height = INT_MIN;
    for (int i = 0; i < index; i++) {
        height = std::max(height, a[i]);
        rtn = std::max(rtn, height - a[i]);
    }

    height = INT_MIN;
    for (int i = n - 1; i > index; i--) {
        height = std::max(height, a[i]);
        rtn = std::max(rtn, height - a[i]);
    }

    cout << rtn << endl;
}