#include <climits>
#include <iostream>
#include <vector>

using namespace std;

int st[4000000];
int A[1000000];

void build(int a[], int v, int tl, int tr) {
    if (tl == tr) {
        st[v] = a[tl];
    } else {
        int tm = (tl + tr) / 2;
        build(a, v*2, tl, tm);
        build(a, v*2+1, tm+1, tr);
        st[v] = st[v*2] + st[v*2+1];
    }
}

/*
void build(int p, int l, int r) {
    if (l == r) {
        st[p] = A[l];
    } else {
        int tm = (l + r) / 2;
        build(p * 2, l, tm);
        build(p * 2 + 1, tm + 1, r);
        st[p] = st[p * 2] + st[p * 2 + 1];
    }
}
 */

void supercomputer() {
    /*
     * This should just be a sum segment tree, with update
     * and range queries.
    */

    int n, q;
    cin >> n >> q;

    // Building the segment tree, all zeros initially

    build(A, 1, 0, n - 1);
}