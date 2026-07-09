#include <bits/stdc++.h>

using namespace std;

struct FenwickTree {
    vector<int> bit;  // binary indexed tree
    int n;

    /**
     * Creates a new Fenwick tree of size n
     */
    FenwickTree(int n) {
        this->n = n;
        bit.assign(n, 0);
    }

    /**
     * Creates a new Fenwick Tree from a vector of elements
     * @param a the vector to initialize
     */
    FenwickTree(vector<int> const &a) : FenwickTree(a.size()) {
        for (int i = 0; i < n; i++) {
            bit[i] += a[i];
            int r = i | (i + 1);
            if (r < n) bit[r] += bit[i];
        }
    }

    /**
     * Helper function for computing sum [0, r]
     */
    int sum(int r) {
        int rtn = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1) {
            rtn += bit[r];
        }
        return rtn;
    }

    /**
     * Inclusive range query over [l, r]
     */
    int sum(int l, int r) {
        return sum(r) - sum(l - 1);
    }

    /**
     * Updates an element of the Fenwick tree
     * @param idx the index to update
     * @param val the new value
     */
    void add(int idx, int val) {
        int delta = val - sum(idx, idx);
        for (; idx < n; idx = idx | (idx + 1)) {
            bit[idx] += delta;
        }
    }
};

