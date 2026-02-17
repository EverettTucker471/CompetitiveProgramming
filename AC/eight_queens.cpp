#include <bits/stdc++.h>

using namespace std;

int main() {
    vector<set<int>> sets(4, set<int>());

    int queen_count = 0;
    bool rtn = true;
    for (int i = 1; i <= 8; i++) {
        for (int j = 1; j <= 8; j++) {
            char c;
            cin >> c;

            if (c == '*') {
                queen_count++;
                vector<int> hashes;
                hashes.push_back(i);
                hashes.push_back(j);
                hashes.push_back(i + j);
                hashes.push_back(i - j);

                for (int k = 0; k < 4; k++) {
                    if (sets[k].count(hashes[k])) {
                        rtn = false;
                        break;
                    }
                    sets[k].insert(hashes[k]);
                }
            }
        }
    }

    cout << ((rtn && queen_count == 8) ? "valid" : "invalid") << "\n";
}