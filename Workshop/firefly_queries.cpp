#include <iostream>
#include <cmath>
#include <vector>

using LL = unsigned long long int;

using namespace std;

LL prefix(vector<LL> part, int n, int i, int block) {
    i -= block * n;
    if (i < 0) {return 0;}

    int last = n - block - 1;

    if (i >= last) {
        if (block == 0) {
            return part[i];
        } else {
            return part[i] - part[block - 1];
        }
    } else {
        return part[last - i - 1] + part[n - 1] - part[block - 1];
    }
}

void firefly_queries() {
    int _;
    cin >> _;

    while (_--) {
        int n, q;
        cin >> n >> q;
        int a[n];
        for (auto& x : a) {cin >> x;}
        vector<LL> part(n);
        part[0] = a[0];
        for (int i = 1; i < n; i++) {
            part[i] = a[i] + part[i - 1];
        }

        while (q--) {
            int l, r;
            LL rtn = 0;
            cin >> l >> r;
            // Index Shifting to 0-indexed
            l--;
            r--;

            int left_block = l / n;
            int right_block = r / n;

            // Full Blocks
            rtn += part[n - 1] * std::max(0, right_block - left_block - 1);

            // I think you can alter this to only have one path
            if (left_block == right_block) {
                rtn += prefix(part, n, r, left_block) - prefix(part, n, l - 1, left_block);
            } else {
                rtn += prefix(part, n, r, right_block) + part[n - 1] - prefix(part, n, l - 1, left_block);
            }

            std::cout << rtn << endl;
        }
    }
}