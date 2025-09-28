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

void c14() {
    int _;
    cin >> _;

    while (_--) {
        int x;
        cin >> x;

        // We need y, with x xor y = o such that y + o > x, x + y > o
        // Minimize the distance between x, y, o
        // Make y and o close to x

        vector<bool> bits;
        int z = x;
        while (z > 0) {
            bits.push_back(z % 2);
            z >>= 1;
        }

        int n = bits.size();
        bool y[n];
        bool o[n];

        y[n - 1] = 0;
        o[n - 1] = 1;
        for (int i = 0; i < n - 1; i++) {
            o[i] = !bits[i];
            y[i] = 1;
        }

        int Y = 0;
        for (int i = n - 1; i >= 0; i--) {
            Y *= 2;
            Y += y[i];
        }

        int O = 0;
        for (int i = n - 1; i >= 0; i--) {
            O *= 2;
            O += o[i];
        }

        bool correct = Y < x && Y + O > x && x + Y > O;
        cout << (correct ? Y : -1) << endl;
    }
}