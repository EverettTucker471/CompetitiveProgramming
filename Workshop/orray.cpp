#include <iostream>
#include <bitset>
#include <vector>
using namespace std;

void orray() {
    int _;
    cin >> _;

    while (_--) {
        int n;
        cin >> n;
        int a[n];
        vector<bitset<30>> b;
        b.reserve(n);

        for (int i = 0; i < n; i++) {
            int val;
            cin >> val;
            a[i] = val;
            b.emplace_back(val);
        }

        unsigned long long int max = 0;
        vector<unsigned long long int> rtn(n);
        for (int i = 0; i < n; i++) {
            if (b[i].count() > max) {
                rtn[0] = a[i];
                max = b[i].count();
            }
        }

        int index = 1;
        while (index < n) {
            unsigned long long int next = 0;
            for (int i = index; i < n; i++) {
                unsigned long long int c = (b[index] & b[i]).count();
                if (c > next) {
                    next = c;
                    rtn[index] = a[i];
                }
            }

        }

        for (auto x : a) {
            cout << x << " ";
        }
    }
}
