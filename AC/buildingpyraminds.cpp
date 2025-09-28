#include<iostream>

using namespace std;


void buildingpyraminds() {
    int n;
    cin >> n;

    int i = 0;
    while ((2 * i + 3) * (i + 1) * (2 * i + 1) / 3 <= n) {
        i++;
    }

    cout << i << endl;
}