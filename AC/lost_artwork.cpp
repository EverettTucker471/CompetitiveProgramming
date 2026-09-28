#include <bits/stdc++.h>

using namespace std;

double dist(pair<int, int> a, pair<int, int> b) {
    return sqrt(
        (a.first - b.first) * (a.first - b.first) +
        (a.second - b.second) * (a.second - b.second)
    );
}

int main() {
    int _;
    cin >> _;

    while (_--) {
        int s;
        cin >> s;

        vector<pair<int, int>> pts(s);
        for (auto& x : pts) cin >> x.first >> x.second;

        sort(pts.begin(), pts.end());

        double total = 0;
        int prev_height = 0;
        for (int i = s - 1; i > 0; i--) {
            if (pts[i - 1].second <= pts[i].second) continue;
            double prop = ((double) pts[i - 1].second - prev_height) / (pts[i - 1].second - pts[i].second);
            total += dist(pts[i], pts[i - 1]) * max(prop, 0.0);
            prev_height = max(prev_height, pts[i - 1].second);
        }

        printf("%.2f\n", total);
    }
}