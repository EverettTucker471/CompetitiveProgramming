#include <utility>
#include<vector>
#include<iostream>
#include<unordered_map>
#include<map>
#include<unordered_set>
#include<set>
#include<cmath>
#include <algorithm>

using namespace std;

void cookingwater() {
    int n;
    cin >> n;

    pair<int, int> interval = {0, 1000};
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        interval.first = std::max(a, interval.first);
        interval.second = std::min(b, interval.second);

        if (interval.second < interval.first) {
            cout << "edward is right" << endl;
            return;
        }
    }

    cout << "gunilla has a point" << endl;
}