#include <bits/stdc++.h>

using namespace std;

long long inverse(long long k, long long m) {
    return k <= 1 ? k : m - (long long)(m / k) * inverse(m % k, m) % m;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, q, p;
    cin >> n >> m >> q >> p;

    vector<vector<int>> table(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> table[i][j];
        }
    }

    vector<vector<int>> residue(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        residue[i][0] = table[i][0] % p;
        for (int j = 1; j < m; j++) {
            residue[i][j] = ((long long int) residue[i][j - 1] * table[i][j]) % p;
        }
    }
    
    vector<vector<int>> mod_inverse(n, vector<int>(m + 1));
    for (int i = 0; i < n; i++) {
        mod_inverse[i][0] = 1;
        for (int j = 1; j <= m; j++) {
            mod_inverse[i][j] = (inverse(table[i][j - 1], p) * mod_inverse[i][j - 1]) % p;
        }
    }

    for (int _ = 0; _ < q; _++) {
        int i1, j1, i2, j2;
        cin >> i1 >> j1 >> i2 >> j2;

        long long sum = 0;
        for (int i = i1; i <= i2; i++) {
            sum += ((long long int) residue[i][j2] * mod_inverse[i][j1]) % p;
        }
        cout << sum << '\n';
    }

    exit(0);
}