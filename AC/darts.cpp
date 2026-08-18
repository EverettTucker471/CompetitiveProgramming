#include <bits/stdc++.h>

using namespace std;

int main() {
    int _;
    cin >> _;

    while (_--) {
        int n;
        cin >> n;

        int score = 0;
        for (int i = 0; i < n; i++) {
            int x, y;
            cin >> x >> y;

            double dist = sqrt(x * x + y * y);

            if (dist == 0) score += 10;
            for (int j = 10; j >= 0; j--) {
                if (dist > 20 * j) {
                    score += 10 - j;
                    break;
                }
            }
        }

        cout << score << '\n';
    }
}