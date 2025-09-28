#include<vector>
#include<iostream>
#include<unordered_map>
#include<map>
#include<unordered_set>
#include<set>
#include<cmath>
#include <algorithm>
#include <climits>
#include <numeric>

using namespace std;

struct Comp {
    int start;

    explicit Comp(int s) : start(s) {};

    bool operator() (const vector<int>& a, const vector<int>& b) const {
        if (a.size() <= start) return true;
        if (a.size() <= start) return false;

        for (int i = start; i < min(a.size(), b.size()); i++) {
            if (a[i] != b[i]) return a[i] < b[i];
        }

        return a.size() < b.size();
    }
};

void f21() {
    int _;
    cin >> _;

    while (_--) {
        int n;
        cin >> n;
        vector<vector<int>> a(n);

        for (int i = 0; i < n; i++) {
            int k;
            cin >> k;

            for (int j = 0; j < k; j++) {
                int x;
                cin >> x;
                a[i].push_back(x);
            }
        }

        // Definitely greedy
        // Take first element min, then pop off length numbers and sort again

        // I feel like this approach is too slow...
    }
}