#include <bits/stdc++.h>

using namespace std;

int cross(pair<int, int> a, pair<int, int> b) {
    return a.first * b.second - a.second * b.first;
}

int main() {
    pair<int, int> x, y, v, w;
    cin >> x.first >> x.second >> y.first >> y.second;
    v.first = y.first - x.first;
    v.second = y.second - x.second;

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x.first >> x.second >> y.first >> y.second;
        w.first = y.first - x.first;
        w.second = y.second - x.second;
    
        cout << (cross(v, w) == 0 ? "NO\n" : "YES\n");
    }
}