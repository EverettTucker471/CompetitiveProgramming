#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;

    // Find largest divisor
    vector<long long> factors;
    long long int n_save = n;
    long long i = 2;
    for (; i * i <= n; i++) {
        if (n % i == 0) {
            factors.push_back(i);
            n /= i;
            i = 1;
        }
    }

    if (n > 1) factors.push_back(n);
    cout << (factors.size() ? n_save - (n_save / factors.front()): 0) << '\n';
}