#include <bits/stdc++.h>

using namespace std;

const long long int MOD = 9223372036854775783;
const long long int P = 31;

bool check(string &s, int n, int len) {
    if (len == 0) return true;

    unordered_set<long long int> set;
    long long hash = 0;
    long long int high_pow = 1;
    for (int i = 0; i < len - 1; i++) {
        high_pow = (high_pow * P) % MOD;
    }

    for (int i = 0; i < len; i++) {
        hash = (hash * P) % MOD;
        hash = (hash + s[i] - 'a' + 1) % MOD;
    }

    set.insert(hash);
    for (int i = len; i < n; i++) {
        hash = (hash - high_pow * (s[i - len] - 'a' + 1)) % MOD;
        hash = (hash * P) % MOD;
        hash = (hash + (s[i] - 'a' + 1)) % MOD;
        if (set.count(hash)) {
            return true;
        }
        set.insert(hash);
    }

    return false;
}

int main() {
    int n;
    string s;
    cin >> n;
    cin >> s;

    // Using polynomial hash
    int left = 0;
    int right = n - 1;
    while (left < right) {
        int len = (left + right + 1) / 2;

        if (check(s, n, len)) {
            left = len;
        } else {
            right = len - 1;
        }
    }

    cout << left << '\n';
}