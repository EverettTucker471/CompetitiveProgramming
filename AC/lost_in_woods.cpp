#include <bits/stdc++.h>

using namespace std;

vector<vector<double>> mat_mul(const vector<vector<double>>& a, const vector<vector<double>>& b) {
  int n = a.size();
  int m = a[0].size();
  int l = b[0].size();

  if (m != b.size()) throw runtime_error("Invalid dimensions");
  vector<vector<double>> rtn(n, vector<double>(l, 0));

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < l; j++) {
      for (int k = 0; k < m; k++) {
        rtn[i][j] += a[i][k] * b[k][j];
      }
    }
  }

  return rtn;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<double>> mat(n, vector<double>(1, 0));
    vector<vector<double>> adj(n, vector<double>(n, 0));

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a][b] = 1;
        adj[b][a] = 1;
    }

    // Normalizing the initial matrix by column
    for (int j = 0; j < n; j++) {
      double sum = 0;
      for (int i = 0; i < n; i++) sum += adj[i][j];
      if (sum > 0) {
        for (int i = 0; i < n; i++) adj[i][j] /= sum;
      }
    }

    mat[0][0] = 1;
    double rtn = 0;
    int ITER = 10000;  // Actually needs a lot more than I was expecting
    for (int i = 0; i < ITER; i++) {
        mat = mat_mul(adj, mat);
        rtn += mat[n - 1][0] * (i + 1);
        mat[n - 1][0] = 0;
    }
    printf("%.8lf\n", rtn);
}