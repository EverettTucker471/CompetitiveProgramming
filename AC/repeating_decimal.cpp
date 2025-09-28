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

void repeating_decimal() {
    int a, b, c;
    while ((cin >> a) && (cin >> b) && (cin >> c)) {
        cout << a / b << ".";
        for (int i = 0; i < c; i++) {
            a -= b * (a / b);
            a *= 10;
            cout << a / b;
        }
        cout << endl;
    }
}