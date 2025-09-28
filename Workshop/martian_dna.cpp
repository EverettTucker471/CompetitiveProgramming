#include <iostream>
#include <climits>
#include <vector>
using namespace std;

// A 2D vector of partial sums in O(NK) maybe?
// Sliding window for each O(NRlog(K)), could potentially make O(NR)
// with one pass

// O(r)
bool checkReq(vector<int> cur, vector<int> req, int r) {
    for (int i = 0; i < r; i++) {
        if (req[i] > cur[i]) {
            return false;
        }
    }
    return true;
}

void print(const vector<int>& a) {
    for (auto x : a) {
        cout << x << " ";
    }
    cout << endl;
}

// Actual input parsing is wrong
// O(nr)
bool sCon(int n, int k, int r, const int a[], const vector<int>& req, int val) {
    // sliding window of size val
    vector<int> cur(r, 0);

    for (int i = 0; i < val; i++) {
        cur[a[i]]++;
        //print(cur);
    }
    if (checkReq(cur, req, r)) {return true;}
    for (int i = val; i < n; i++) {
        cur[a[i - val]]--;
        cur[a[i]]++;
        //print(cur);
        if (checkReq(cur, req, r)) {return true;}
    }
    return false;
}

void martianDNA() {
    int n, k, r;
    cin >> n >> k >> r;
    int a[n];
    for (auto& x: a) {cin >> x;}
    vector<int> req(k, 0);

    for (int i = 0; i < r; i++) {
        int index;
        cin >> index;
        cin >> req[index];
    }

    // Testing sCon - Mandatory to save future headache
    //sCon(n, k, r, a, req, 3);

    if (!sCon(n, k, r, a, req, n)) {cout << "impossible" << endl; return;}

    int left = r;
    int right = n;
    while (left < right) {
        int mid = (left + right) / 2;

        if (sCon(n, k, r, a, req, mid)) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }

    cout << left << endl;
}