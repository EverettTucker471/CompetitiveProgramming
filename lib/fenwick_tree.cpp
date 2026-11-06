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

#define ll long long

class LazySegTree {
    int size;
    vector<ll> mx;    // current max of range (including pending lazy)
    vector<ll> lz;    // pending add
    const ll NEG_INF = LLONG_MIN / 2;  // identity for max; divide to avoid overflow on add
    
    void apply_lazy(int node, ll v) {
        mx[node] += v;
        lz[node] += v;
    }
    
    void propagate(int node) {
        if (lz[node] != 0) {
            apply_lazy(2*node + 1, lz[node]);
            apply_lazy(2*node + 2, lz[node]);
            lz[node] = 0;
        }
    }
    
    void update_range(int l, int r, ll v, int node, int lx, int rx) {
        if (lx >= r || rx <= l) return;
        if (lx >= l && rx <= r) {
            apply_lazy(node, v);
            return;
        }
        propagate(node);
        int m = (lx + rx) / 2;
        update_range(l, r, v, 2*node + 1, lx, m);
        update_range(l, r, v, 2*node + 2, m, rx);
        mx[node] = max(mx[2*node + 1], mx[2*node + 2]);
    }
    
    ll range_query(int l, int r, int node, int lx, int rx) {
        if (lx >= r || rx <= l) return NEG_INF;
        if (lx >= l && rx <= r) return mx[node];
        propagate(node);
        int m = (lx + rx) / 2;
        ll left = range_query(l, r, 2*node + 1, lx, m);
        ll right = range_query(l, r, 2*node + 2, m, rx);
        return max(left, right);
    }

public:
    LazySegTree(int n) {
        size = 1;
        while (size < n) size *= 2;
        mx.assign(2 * size, 0);
        lz.assign(2 * size, 0);
    }
    
    void update_range(int l, int r, ll v) {
        update_range(l, r, v, 0, 0, size);
    }
    
    ll range_query(int l, int r) {
        return range_query(l, r, 0, 0, size);
    }
};
