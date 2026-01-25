#include <bits/stdc++.h>

using namespace std;

int main() {
    int _;
    cin >> _;

    while (_--) {
        int n, s, x;
        cin >> n >> s >> x;

        int a_sum = 0;
        while (n--) {
            int z;
            cin >> z;
            a_sum += z;
        }

        bool rtn = (s - a_sum >= 0) && (s - a_sum) % x == 0;
        cout << (rtn ? "YES" : "NO") << "\n";
    }
}