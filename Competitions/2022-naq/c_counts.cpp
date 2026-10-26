#include <bits/stdc++.h>

using namespace std;

int main() {
    long n, k;
    cin >> n >> k;
    
    long cur = 0;
    int rtn = 0;
    for (int i = 1; i <= n; i++) {
        cur *= (long) pow(10L, (long) floor(log10(i)) + 1);
        cur += i;
        cur %= k;
        rtn += (cur == 0);
    }

    cout << rtn << '\n';
}