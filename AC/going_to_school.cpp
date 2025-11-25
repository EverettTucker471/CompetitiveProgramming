#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    cin >> s;
    int n = s.size();

    vector<int> top(n + 1, 100000);
    vector<int> bot(n + 1, 100000);

    bot[0] = 1;
    top[0] = 0;

    for (int i = 1; i <= n; i++) {
        if (s[i - 1] == 'N') {
            top[i] = min(top[i], top[i - 1] + 1);
            bot[i] = min(bot[i], bot[i - 1]);
        } else if (s[i - 1] == 'S') {
            top[i] = min(top[i], top[i - 1]);
            bot[i] = min(bot[i], bot[i - 1]  +1);
        } else if (s[i - 1] == 'B') {
            bot[i] = min(bot[i], bot[i - 1]  +1);
            top[i] = min(top[i], top[i - 1] + 1);
        }
        top[i] = min(top[i], bot[i] + 1);
        bot[i] = min(bot[i], top[i] + 1);
    }

    cout << top[n] << '\n';
}