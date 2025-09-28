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

void b12() {
    int _;
    cin >> _;

    while (_--) {
        int n;
        cin >> n;
        string a;
        cin >> a;

        if (a[0] == 's') {
            a = a.substr(1, n - 1);
            n--;
        }

        if (n > 0 && a[n - 1] == 'p') {
            a = a.substr(0, n - 1);
            n--;
        }

        a.erase(std::remove(a.begin(), a.end(), '.'), a.end());

        int x = a.find("sp");
        int y = a.find("ps");

        cout << ((x < 0 && y < 0) ? "YES" : "NO") << endl;
    }
}