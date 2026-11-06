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

vector<vector<long>> mat_mul_mod(const vector<vector<long>>& a, const vector<vector<long>>& b, long m) {
    int n = a.size();
    int k_dim = a[0].size();
    int l = b[0].size();

    if (k_dim != b.size()) throw runtime_error("Invalid dimensions");
    vector<vector<long>> rtn(n, vector<long>(l, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < l; j++) {
            for (int k = 0; k < k_dim; k++) {
                long product = (a[i][k] * b[k][j]) % m;
                rtn[i][j] = (rtn[i][j] + product) % m;
            }
        }
    }

    return rtn;
}

/**
 * Binary exponentiation for matrix powers
 * Computes S_ij = (a^k)_ij % m
 */
vector<vector<long>> mat_pow_mod(vector<vector<long>> a, long b, const long m) {
  int n = a.size();
  if (n == 0 || n != a[0].size()) {
      throw runtime_error("Matrix must be square");
  }
  
  vector<vector<long>> res(n, vector<long>(n, 0));
  
  for (int i = 0; i < n; i++) {
    res[i][i] = 1;
  }

  for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
          a[i][j] = (a[i][j] % m + m) % m;
      }
  }

  while (b > 0) {
      if (b & 1) {
        res = mat_mul_mod(res, a, m);
      }
      a = mat_mul_mod(a, a, m);
      b >>= 1;
  }
  return res;
}