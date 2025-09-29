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

void mirror_strings() {
    int uppercase_length = 5;
    int lowercase_length = 2;

    int l, r;
    cin >> l >> r;

    // Compute mirror strings of length l, then l + 1, l + 2, ... r

    // Either only lowercase, or only uppercase
    // The answer for length n is (n / 2)^2 + (n / 2)^5

    vector<int> p2((r + 3) / 2);
    vector<int> p5((r + 3) / 2);
    p2[0] = 1;
    p5[0] = 1;

    int mod = 1000000007;
    for (int i = 1; i < p2.size(); i++) {
        p2[i] = ((long long) p2[i - 1] * 2) % mod;
        p5[i] = ((long long) p5[i - 1] * 5) % mod;
    }

    long long sum = 0;
    for (int i = l; i <= r; i++) {
        sum = (sum + p2[(i + 1) / 2] + p5[(i + 1) / 2]) % mod;
    }

    cout << sum << endl;
}