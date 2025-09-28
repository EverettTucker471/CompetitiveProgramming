#include<vector>
#include<iostream>
#include<unordered_map>
#include<map>
#include<unordered_set>
#include<set>
#include<cmath>
#include<climits>
#include <algorithm>

using namespace std;

void b9() {
    int _;
    cin >> _;

    while (_--) {
        int n, k;
        cin >> n >> k;
        int b[k], c[k];
        for (int i = 0; i < k; i++) {
            cin >> b[i];
            cin >> c[i];
        }

        vector<int> a(k, 0);
        for (int i = 0; i < k; i++) {
            a[b[i] - 1] += c[i];
        }

        std::sort(a.begin(), a.end(), std::greater<>());

        int i = 0;
        long long int rtn = 0;
        for (auto x : a) {
            if (i >= n) {break;}
            rtn += x;
            i++;
        }

        cout << rtn << endl;
    }
}
