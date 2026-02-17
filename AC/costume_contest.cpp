#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;

    map<string, int> map;

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        map[s]++;
    }

    vector<string> rtn;
    int min_freq = INT_MAX;
    for (auto x : map) {
        if (x.second == min_freq) {
            rtn.push_back(x.first);
        } else if (x.second < min_freq) {
            min_freq = x.second;
            rtn.clear();
            rtn.push_back(x.first);
        }
    }

    for (auto x : rtn) {
        cout << x << '\n';
    }
}