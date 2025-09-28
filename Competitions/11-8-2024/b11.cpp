#include<vector>
#include<iostream>
#include<unordered_map>
#include<map>
#include<unordered_set>
#include<set>
#include<cmath>
#include<climits>
#include <algorithm>

using ll = long long int;
using namespace std;

void b11() {
    int n;
    cin >> n;

    ll offset = 0;
    unsigned long long sum = 0;

    unordered_map<ll, ll> map;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        sum += x;
        map[x]++;
    }

    int q;
    cin >> q;

    while (q--) {
        string s;
        cin >> s;

        if (s == "SET") {
            int x, y;
            cin >> x >> y;
            x -= offset;
            y -= offset;
            if (x != y && map[x] > 0) {
                sum += (y - x) * map[x];
                map[y] += map[x];
                map[x] = 0;
            }
        } else {
            long long int x;
            cin >> x;
            offset += x;
            sum += n * x;
        }

        cout << sum << '\n';
    }
}