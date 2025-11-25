#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<vector<double>> pt(n, vector<double>());
    vector<pair<double, string>> arr;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 3; j++) {
            double x;
            cin >> x;
            pt[i].push_back(x);
        }
        string s;
        cin >> s;
        arr.push_back({0, s});
    }

    // computing intersections
    for (int i = 0; i < n; i++) {
        if (pt[i][2] == 0) {
            arr[i].first = INT_MIN;
            continue;
        }

        double x = pt[i][0] - pt[i][1] / pt[i][2];
        if (x < pt[i][0]) {
            arr[i].first = INT_MIN;
            continue;
        }

        arr[i].first = x;
    }

    sort(arr.begin(), arr.end());

    for (int i = 0; i < n; i++) {
        if (arr[i].first > INT_MIN) cout << arr[i].second << endl;
    }
}