#include <iostream>
#include <vector>
#include <climits>

using namespace std;

void dishonest_lottery() {
    int n;
    cin >> n;

    vector<int> count(50, 0);

    for (int _ = 0; _ < 10 * n; _++) {
        for (int i = 0; i < 5; i++) {
            int x;
            cin >> x;
            count[x - 1]++;
        }
    }

    bool flag = true;
    for (int i = 0; i < 50; i++) {
        if (count[i] > (2 * n)) {
            cout << i + 1 << " ";
            flag = false;
        }
    }
    if (flag) {cout << -1;}
}
