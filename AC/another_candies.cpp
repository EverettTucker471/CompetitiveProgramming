#include <bits/stdc++.h>

using namespace std;

int main() {
    int _;
    cin >> _;

    while (_--) {
        int n;
        cin >> n;

        long long int sum = 0;
        for (int i = 0; i < n; i++) {
            long long int x;
            cin >> x;
            sum = (sum + x) % n;
        }

        cout << (sum == 0 ? "YES": "NO") << '\n';
    }
}