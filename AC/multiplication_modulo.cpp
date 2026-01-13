#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;

    unsigned long long int mod = 1000000007;

    unsigned long long int rtn = 1;
    while (n--) {
        unsigned long long int a;
        cin >> a;
        a %= mod;

        rtn = (rtn * a) % mod;
    }

    cout << rtn << "\n";
}