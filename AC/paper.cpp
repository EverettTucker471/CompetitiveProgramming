#include <bits/stdc++.h>

using namespace std;

int main() {
    vector<double> lengths;
    lengths.push_back(pow(2, -0.75));
    lengths.push_back(pow(2, -1.25));

    int n;
    cin >> n;
    int a[n - 1];
    vector<int> b;
    for (auto& x : a) cin >> x;

    for (int i = 2; i < n; i++) {
        lengths.push_back(lengths[lengths.size() - 2] / 2);
    }

    const long total = (long) pow(2, n - 1);
    long size = total / 2;
    long cur = 0;

    for (int i = 0; i < n - 1; i++) {
        b.push_back(0);
        // Fast-forward this while loop to constant time
        while (a[i] > 0 && cur + size <= total) {
            cur += size;
            a[i]--;
            b[i]++;
        }
        size /= 2;
    }

    double rtn = 0;
    n = b.size();
    for (int i = n - 1; i >= 0; i--) {
        rtn += lengths[i] * (b[i] / 2);
        if (i > 0) b[i - 1] += (b[i] / 2);
    }

    if (cur == total) {
        printf("%.8lf\n", rtn);
    } else {
        cout << "impossible\n";
    }
}