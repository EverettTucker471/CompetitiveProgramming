#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using dd = int;
using ii = pair<dd, dd>;
using vi =  vector<dd>;
using vii = vector<ii>;
using vvi = vector<vi>;
using vvii = vector<vii>;


bool check(const double power[], const double mult[], const int perm[], int n, double p) {
    double rtn = 0;
    for (int i = 0; i < n; i++) {
        rtn += power[perm[i]] * mult[i];
    }
    return rtn > p;
}

void s() {
    int n;
    double p;
    cin >> n >> p;
    double power[n];
    double mult[n];
    for (auto& x : power) {cin >> x;}
    for (auto& x : mult) {cin >> x;}

    int rtn = 0;
    int perm[n];
    for (int i = 0; i < n; i++) {
        perm[i] = i;
    }
    rtn += check(power, mult, perm, n, p);
    while (std::next_permutation(perm, perm + n)) {
        rtn += check(power, mult, perm, n, p);
    }

    cout << rtn;
}