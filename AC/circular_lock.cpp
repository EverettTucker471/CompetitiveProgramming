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

long long gcd(long long a, long long b) {
    while (b) {
        long long r = a % b;
        a = b;
        b = r;
    }

    return a;
}

void circular_lock() {
    int _;
    cin >> _;

    while (_--) {
        int p1, p2, p3, p4;
        int sx, sy, sz, sw;
        cin >> sx >> sy >> p1 >> p2;
        cin >> sz >> sw >> p3 >> p4;

        // Converting using the theorem
        long long p = gcd(p1, gcd(p2, gcd(p3, p4)));
        sx %= p;
        sy %= p;
        sz %= p;
        sw %= p;
        
        // Going around in a counter-clockwise circle from w to z
        sy = (sy + 10 * p - sw) % p;
        sx = (sx + 10 * p - sy) % p;
        sz = (sz + 10 * p - sx) % p;

        cout << ((sz % p) == 0 ? "Yes" : "No") << endl;
    }
}