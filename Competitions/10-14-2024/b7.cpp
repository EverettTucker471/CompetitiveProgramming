#include<vector>
#include<iostream>
#include<unordered_map>
#include<map>
#include<unordered_set>
#include<set>
#include<cmath>
#include<climits>
#include <algorithm>

using namespace std;

void b7() {
    // Precompute powers of two
    long long int powers[100000];
    powers[0] = 1;
    int mod = 1000000007;
    for (int i = 1; i < 100000; i++) {
        powers[i] = (powers[i - 1] * 2) % mod;
    }

    int t;
    cin >> t;
    int z;

    for (int i = 0; i < t; i++) {cin >> z;}
    for (int i = 0; i < t; i++) {
        cin >> z;
        cout << powers[z] << endl;
    }

    /*
    int N, K;
    cin >> N >> K;
    vector<vector<int>> C(N + 1, vector<int>(N + 1, 0));
    // int C[N][N];

    for (int n = 0; n < N + 1; n++) { // loop over n from 0 to N-1 (inclusive)
        C[n][0] = 1;
        C[n][n] = 1;
        for (int k = 1; k < n; k++) { // loop over k from 1 to n-1 (inclusive)
            C[n][k] = C[n][k - 1] + C[n - 1][k - 1];
            // C[n][k] = C[n - 1][k] + C[n - 1][k - 1];
        }
    }

   for (const auto& x : C) {
       for (auto y : x) {
           cout << y << " ";
       }
       cout << endl;
   }

   cout << C[N][K];
   */
}