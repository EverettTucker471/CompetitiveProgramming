#include<vector>
#include<iostream>
#include<unordered_map>
#include<map>
#include<unordered_set>
#include<set>
#include<cmath>
#include <algorithm>
#include <climits>
#include <numeric>

using namespace std;

void guess_number() {
    int left = 1;
    int right = 1000;
    while (left <= right) {
        int mid = (left + right) / 2;
        cout << mid << endl;
        flush(cout);

        string a;
        cin >> a;
        if (a == "lower") {
            right = mid - 1;
        } else if (a == "higher") {
            left = mid + 1;
        } else {
            return;
        }
    }
}