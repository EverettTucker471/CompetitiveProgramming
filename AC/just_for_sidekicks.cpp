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
     * @param delta the change to the current value
     */
    void add(int idx, int delta) {
        for (; idx < n; idx = idx | (idx + 1)) {
            bit[idx] += delta;
        }
    }
};

int main() {
    int n, q;
    cin >> n >> q;
    vector<int> values(6);
    for (auto& x : values) cin >> x;

    string types;
    cin >> types;

    vector<int> v(n);
    vector<FenwickTree> trees(6, FenwickTree(n));

    for (int i = 0; i < n; i++) {
        int idx = (int) (types.at(i) - '1');
        v[i] = idx;
        trees[idx].add(i, 1);
    }

    for (int i = 0; i < q; i++) {
        int x;
        cin >> x;

        if (x == 1) {
            // Replace index k with type p
            int k, p;
            cin >> k >> p;
            k--;
            p--;
            trees[v[k]].add(k, -1);
            trees[p].add(k, 1);
            v[k] = p;
        } else if (x == 2) {
            int p, v;
            cin >> p >> v;
            values[p - 1] = v;
        } else {
            int l, r;
            cin >> l >> r;
            long long int rtn = 0;
            for (int i = 0; i < 6; i++) {
                rtn += ((long long int) values[i]) * trees[i].sum(l - 1, r - 1);
            }
            cout << rtn << '\n';
        }
    }
}