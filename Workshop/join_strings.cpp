#include<vector>
#include<iostream>
#include<unordered_map>
#include<map>
#include<unordered_set>
#include<set>
#include<cmath>
#include <algorithm>
#include <sstream>

using namespace std;

void join_strings() {
    int n;
    cin >> n;
    string arr[n];
    for (auto& x : arr) cin >> x;

    vector<int> last(n, -1);  // Path compression array
    vector<int> after(n, -1);
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;

        int x = a;
        if (last[x] >= 0) {
            after[last[x]] = b;
        } else {
            after[x] = b;
        }
        last[x] = last[b] >= 0 ? last[b] : b;
    }

    vector<bool> present(n, false);
    for (auto x : after) {
        if (x >= 0) {
            present[x] = true;
        }
    }

    int cur;
    for (int i = 0; i < n; i++) {
        if (!present[i]) cur = i;
    }

    std::stringstream ss;
    while (cur >= 0) {
        ss << arr[cur];
        cur = after[cur];
    }

    cout << ss.str() << endl;
}