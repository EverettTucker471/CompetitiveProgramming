#include <bits/stdc++.h>

using namespace std;

int CUTOFF = 1e9;

void lottery() {
    int _;
    cin >> _;

    while (_--) {
        int n;
        cin >> n;
        int p[n];
        for (auto& x : p) cin >> x;

        // Find the LCM of all the numbers in p
        unordered_map<int, int> f;
        for (int w : p) {
            unordered_map<int, int> temp;
            for (int i = 2; i * i <= w; i++) {
                    if (w % i == 0) {
                    temp[i]++;
                    w /= i;
                    i = 1;
                }
            }
            temp[w]++;

            for (auto x : temp) {
                f[x.first] = max(f[x.first], x.second);
            }
        }

        long long rtn = 1;
        for (auto x : f) {
            // cout << x.first << " " << x.second << endl;
            for (int i = 0; i < x.second; i++) {
                rtn *= x.first;
                if (rtn > CUTOFF) break;
            }
        }

        if (rtn > CUTOFF) {
            cout << "More than a billion." << endl;
        } else {
            cout << rtn << endl;
        }
    }
}