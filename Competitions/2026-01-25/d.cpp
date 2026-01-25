#include <bits/stdc++.h>

using namespace std;


int main() {
    int _;
    cin >> _;

    while (_--) {
        int n;
        cin >> n;
        int a[n], b[n];
        for (auto& x : a) cin >> x;  // Swords
        for (auto& x : b) cin >> x;  // Monsters

        // Partials for the monsters array
        vector<int> m_part(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            m_part[i] = m_part[i - 1] + b[i - 1];
        }

        // Binary search on the difficulty level x
        long long int rtn = 0;
        int left = 1;
        int right = 0;
        for (auto x : a) right = max(right, x);


        // Should be ternary search not binary?
        while (left < right) {
            int mid = (left + right) / 2;

            // Find out how many swords we can use
            int swords = 0;
            for (auto x : a) {
                if (x >= mid) swords++;
            }

            // Find out how many levels we can get to with those swords
            int level = 0;
            for (int i = 0; i <= n; i++) {
                if (m_part[i] > swords) {
                    level = i - 1;
                    break;
                }
            }

            rtn = max(rtn, (long long int) level * mid);
        }

    }
}