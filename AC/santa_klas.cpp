#include<vector>
#include<iostream>
#include<unordered_map>
#include<map>
#include<unordered_set>
#include<set>
#include<cmath>
#include <algorithm>

using namespace std;

void santa_klas() {
    double h;
    int v;
    cin >> h >> v;

    if (v <= 180) {
        cout << "safe" << endl;
    } else {
        v = abs(v - 270);
        cout << (int) (h / cos(v * M_PI / 180));
    }
}