#include <bits/stdc++.h>

using namespace std;

int main() {
    double t;
    int n;
    cin >> t;
    cin >> n;

    // double min_weight = DBL_MAX;
    long s = 0;
    vector<int> w(n);
    for (auto& x : w) cin >> x;
    for (auto x : w) s += x;

    for (int i = n; i <= n + 500; i++) {
        int m = ceil(s / i);

        int min_top = INT_MAX;
        for (auto x : w) {
            min_top = min(min_top, x % m);
        }

        cout << min_top << '\n';
        if (min_top == 0 || (double) min_top / m > t) {
            break;
        }

        cout << m << '\n';
    }
}