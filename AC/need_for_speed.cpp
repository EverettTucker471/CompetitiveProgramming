#include <iostream>
#include <climits>

using namespace std;

// Probably binary searchDFS on c, but I haven't read it yet - non-int tho
// Also what are bounds for c?

bool cond(int n, int t, const int d[], const int s[], long double val) {
    long double time = 0;

    for (int i = 0; i < n; i++) {
        if (val + s[i] > 0) {
            time += d[i] / (val + s[i]);
        } else {
            return false;
        }
    }

    return time <= t;
}

void need4Speed() {
    int n, t;
    cin >> n >> t;
    int d[n];
    int s[n];
    for (int i = 0; i < n; i++) {
        cin >> d[i];
        cin >> s[i];
    }

    // This is going to get very weird
    long double left = INT_MIN;
    long double right = INT_MAX;

    while (right - left >= 0.0000001) {
        long double mid = (left + right) / 2;

        if (cond(n, t, d, s, mid)) {
            right = mid;
        } else {
            left = mid;
        }
    }

    printf( "%.9Lf\n", right );
}