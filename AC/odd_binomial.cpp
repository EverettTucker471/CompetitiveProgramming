#include <bits/stdc++.h>

using namespace std;

long long count(long long n) {
    long long rtn = 0;
    while (n) {
        rtn += n % 2;
        n /= 2;
    }
    return rtn;
}

int main() {
    long long n;
    cin >> n;

    vector<bool> decomp;
    while (n > 1) {
        if (n % 2) {
            n--;
            decomp.push_back(1);
        } else {
            n /= 2;
            decomp.push_back(0);
        }
    }

    reverse(decomp.begin(), decomp.end());

    long long rtn = 1;
    long long index = 1;
    for (auto x : decomp) {
        if (!x) {
            rtn *= 3;
            index *= 2;
        } else {
            rtn += (long long) pow(2, (long long) count(index));
            index++;
        }
    }

    cout << rtn << '\n';

    return 0;
} 