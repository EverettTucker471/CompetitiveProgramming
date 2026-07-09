#include <bits/stdc++.h>

using namespace std;

long long factorial(long long k) {
    long long rtn = k;
    while (--k > 0) rtn *= k;
    return rtn;
}

int n;
int cnt = 0;
vector<vector<int>> mat;
long long int best = 0;

int dfs(long long v, int s, vector<bool> used) {
    // cout << v << " " << s << "\n";
    int rtn = 1;
    if (s == n) {
        if (!best) best = v;
        return rtn;
    }
    int end = v % n;
    for (int i = 0; i < n; i++) {
        if (!used[i] && !mat[end][i]) {
            vector<bool> temp = used;
            temp[i] = true;
            rtn += dfs(v * n + i, s + 1, temp);
        }
    }
    return rtn + 1;
}

int main() {
    int _;
    cin >> _;

    while (_--) {
        int m;
        cin >> n;
        map<string, int> colors;
        vector<string> colors_rev;
        for (int i = 0; i < n; i++) {
            string a;
            cin >> a;
            colors[a] = i;
            colors_rev.push_back(a);
        }

        cin >> m;
        mat.assign(n, vector<int>(n, false));
        vector<vector<bool>> mat(n, vector<bool>(n, false));
        for (int i = 0; i < m; i++) {
            string a, b;
            cin >> a >> b;
            mat[colors[a]][colors[b]] = true;
            mat[colors[b]][colors[a]] = true;
        }

        for (int i = 0; i < n; i++) {
            vector<bool> used(n, false);
            used[i] = true;
            cnt += dfs(i, 1, used);
        }

        cout << cnt << "\n";
        vector<string> res;
        while (best) {
            res.push_back(colors_rev[best % n]);
            best /= n;
        }
        reverse(res.begin(), res.end());
        for (string x : res) cout << x << " ";
        cout << "\n";
    }
}