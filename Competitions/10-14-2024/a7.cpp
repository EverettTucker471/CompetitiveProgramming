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

void a7() {
    int _;
    cin >> _;

    while (_--) {
        string a;
        string b;
        cin >> a >> b;

        int i = 0;
        while (i < a.size() && i < b.size() && a[i] == b[i]) {
            i++;
        }

        cout << a.size() + b.size() - std::max(i - 1, 0) << endl;
    }
}