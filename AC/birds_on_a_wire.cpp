#include <bits/stdc++.h>

using namespace std;

int main() {
    long l, d, n;
    cin >> l >> d >> n;

    vector<long> birds(n);
    for (auto& x : birds) {
        cin >> x;
    }
    birds.push_back(l);

    sort(birds.begin(), birds.end());
    vector<long> dist(n + 1);

    dist[0] = birds[0];
    for (int i = 0; i < n; i++) {
        dist[i + 1] = birds[i + 1] - birds[i];
    }

    // Accounting for pole distances
    dist[0] += d - 6;
    dist[n] += d - 6;

    long rtn = 0;
    for (long x : dist) {
        rtn += max((x / d) - 1, 0L);
    }

    cout << rtn << '\n';
}