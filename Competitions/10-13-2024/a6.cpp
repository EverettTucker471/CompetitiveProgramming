#include<vector>
#include<iostream>
#include<unordered_map>
#include<map>
#include<unordered_set>
#include<set>
#include<cmath>
#include<climits>

using namespace std;

void a6() {
    int _;
    cin >> _;

    while (_--) {
        int n, r;
        cin >> n >> r;
        int a[n];
        int sum = 0;
        for (auto& x : a) {cin >> x; sum += x;}

        int single = 0;
        for (int x : a) {
            if (x % 2) {
                single++;
            }
            r -= x / 2;
        }

        cout << sum - std::max(0, single - r) * 2 << endl;
        /*
        cout << "Sum: " << sum << endl;
        cout << "R : " << r << endl;
        cout << "Single: " << single;
         */
    }
}

