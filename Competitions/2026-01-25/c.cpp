#include <bits/stdc++.h>

using namespace std;


int main() {
    int _;
    cin >> _;

    while (_--) {
        int n, q;
        cin >> n >> q;
        int a[n], b[n];
        for (auto& x : a) cin >> x;
        for (auto& x : b) cin >> x;

        vector<pair<int, int>> queries(q);
        for (auto& x : queries) {
            cin >> x.first;
            cin >> x.second;
        }

        a[n - 1] = max(a[n - 1], b[n - 1]);
        for (int i = n - 2; i >= 0; i--) {
            a[i] = max(max(a[i + 1], b[i]), a[i]);
        }

        // Take partials
        vector<int> pa(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            pa[i] = a[i - 1] + pa[i - 1];
        }

        for (auto query : queries) {
            cout << pa[query.second] - pa[query.first - 1] << " ";
        }
        cout << "\n";
    }
}