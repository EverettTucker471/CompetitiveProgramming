#include <bits/stdc++.h>

using namespace std;

int main() {
    int r, c;
    cin >> r >> c;
    vector<char> moves(r + c - 2);
    for (auto& x : moves) cin >> x;

    // Top and right first
    vector<int> t_count(c + 1, 0), r_count(c + 1, 0);

    bool has_top = false;
    for (int i = 1; i <= c; i++) {
        if (moves[i - 1] == 'D') has_top = true;
        if (has_top && moves[i - 2] != 'D' && moves[i - 1] == 'R') {
            t_count[i] = t_count[i - 1] + 1;
        } else {
            t_count[i] = t_count[i - 1];
        }

        if (i < c && moves[i - 1] == 'D' && moves[i] != 'R') {
            r_count[i] = r_count[i - 1] + 1;
        } else {
            r_count[i] = r_count[i - 1];
        }
    }

    for (auto x : t_count) {
        cout << x << " ";
    }
    cout << endl;
    for (auto x : r_count) {
        cout << x << " ";
    }
    cout << endl;
}