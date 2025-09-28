#include <iostream>
#include <cmath>

using namespace std;

// We're gonna need this inverted
unsigned long long int val(int a, int b, int k) {
    if (b >= a) {return a;}
    k = min(k, a / b + 1);
    return (long long int) a * k - b * (k * (k - 1)) / 2;
}

// Gives the sum of k_i for the cutoff m
// O(n)
int count(int a[], int b[], int n, unsigned long long int m) {
    for (int i = 0; i < n; i++) {
        int div = a[i] / b[i] + 1;
        unsigned long long int max_score = a[i] * div - b[i] * div * (div - 1) / 2;

    }
    return 0;
}

// This is a tough one, and would be awesome if I got it
void bomb() {
    int _;
    cin >> _;

    while (_--) {
        int n, k;
        cin >> n >> k;

        int a[n], b[n];
        for (auto& x : a) {cin >> x;}
        for (auto& x : b) {cin >> x;}

        // Make r more accurate to save time on average
        unsigned long long int l = 0;
        unsigned long long int r = 0; // Absolute max is 1e17 + 1e8 I think
        for (int i = 0; i < n; i++) {
            r = max(r, val(a[i], b[i], k));
        }

        // We go for the value above, because it is easier to extract the final answer from that
        // I know what I mean, but you don't really yet
        while (l < r) {
            unsigned long long int m = (l + r) / 2;

            int c = count(a, b, n, m);
            if (c >= k) {
                r = m;
            } else {
                l = m + 1;
            }
        }

        // Compensate for potentially being above the point, subtract threshold * (r - k)


    }
}