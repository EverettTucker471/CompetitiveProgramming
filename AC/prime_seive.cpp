#include <bits/stdc++.h>

using namespace std;

int main() {
    long long int n, q;
    cin >> n >> q;

    vector<bool> p(n + 1, true);
    p[0] = false;
    p[1] = false;

    for (long long int i = 2; i <= n; i++) {
        if (p[i]) {
            for (long long int j = i * i; j <= n; j += i) {
                p[j] = false;
            }
        }
    }

    int count = 0;
    for (auto x : p) count += x;
    cout << count << '\n';

    int query;
    while (q--) {
        cin >> query;
        cout << (p[query] ? "1\n" : "0\n");
    }
}