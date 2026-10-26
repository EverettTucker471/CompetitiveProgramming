#include <bits/stdc++.h>

using namespace std;

int main() {
    long m, n, k;
    cin >> k >> m >> n;

    bool win = false;
    if (k >= m) {
        win = ((k - m) % (m + n)) < n;
    }

    cout << (win ? "Alex" : "Barb") << '\n';
}