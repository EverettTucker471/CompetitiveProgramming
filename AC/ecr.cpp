#include <bits/stdc++.h>

using namespace std;

int main() {
    // Find shortest and largest multiple K in [1, n - 1]

    long long int n, k;
    cin >> n >> k;

    long long int smallest = (k < n) ? k : 0;
    long long int largest = k * ((long long int) ceil((double) n / k) - 1);

    if (smallest != 0 && smallest < largest) {
        cout << smallest - largest + n << '\n';
    } else {
        cout << n - 1 << '\n';
    }
}