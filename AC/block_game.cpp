#include <bits/stdc++.h>

using namespace std;

bool wins(long a, long b, bool turn) {
    if (b == 0) return !turn;

    // If we can take either 1 or all, one is optimal and we win
    long x = a / b;
    if (x >= 2) return turn;

    return wins(b, a % b, !turn);
}

int main() {
    long n, m;
    cin >> n >> m;
    cout << (wins(max(n, m), min(n, m), true) ? "win" : "lose") << '\n';
}