#include <vector>
#include <iostream>
#include <unordered_map>
#include <map>
#include <unordered_set>
#include <set>
#include <cmath>
#include <algorithm>
#include <climits>
#include <numeric>

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