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

int local_matches(string s, int i, int n) {
    int rtn = 0;
    for (int j = i - 3; j <= i; j++) {
        if (0 <= j && j + 3 < n) {
            if (s[j] == '1' && s[j + 1] == '1' && s[j + 2] == '0' && s[j + 3] == '0') {
                rtn++;
            }
        }
    }
    return rtn;
}

void c9() {
    int _;
    cin >> _;
    while (_--) {
        string s;
        cin >> s;
        int n = s.size();
        int q;
        cin >> q;
        std::pair<int, int> queries[q];
        for (auto& x : queries) {
            cin >> x.first;
            cin >> x.second;
        }

        int count = 0;
        for (int i = 0; i < n - 3; i++) {
            if (s[i] == '1' && s[i + 1] == '1' && s[i + 2] == '0' && s[i + 3] == '0') {
                count++;
            }
        }

        for (auto x : queries) {
            x.first--;

            // If String is changed
            if (s[x.first] - '0' != x.second) {
                int bef = local_matches(s, x.first, n);
                s[x.first] = (char) ('0' + x.second);
                int aft = local_matches(s, x.first, n);
                count += (aft - bef);
            }
            cout << (count > 0 ? "YES" : "NO") << endl;
        }
    }
}