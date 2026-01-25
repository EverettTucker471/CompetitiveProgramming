#include <bits/stdc++.h>

using namespace std;

long long int computeScore(int a[], const vector<int>& m_part, int mid, int n) {
    // Find out how many swords we can use
    int swords = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] >= mid) swords++;
    }

    // Find out how many levels we can get to with those swords
    int level = n;
    for (int i = 0; i <= n; i++) {
        if (m_part[i] > swords) {
            level = i - 1;
            break;
        }
    }

    return (long long int) mid * level;
}


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
        long long int left = 1;
        long long int right = 0;
        for (long long int x : a) right = max(right, x);

        // Computing extrema
        long long int rtn = max(computeScore(a, m_part, 1, n), computeScore(a, m_part, right, n));

        // Should be ternary search not binary?
        while (left <= right) {
            long long int m1 = (2 * left + right) / 3;
            long long int m2 = (left + 2 * right + 1) / 3;
            // cout << "Difficulty: " << m1 << " " << m2 << endl;

            long long int s1 = computeScore(a, m_part, m1, n);
            long long int s2 = computeScore(a, m_part, m2, n);
            // cout << "Scores: " << s1 << " " << s2 << endl;

            rtn = max(rtn, max(s1, s2));

            if (s1 > s2) {
                right = m2 - 1;
            } else {
                left = m1 + 1;
            }
        }

        cout << rtn << "\n";
    }
}