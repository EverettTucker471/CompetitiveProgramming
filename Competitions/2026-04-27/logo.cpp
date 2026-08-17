#include <bits/stdc++.h>

using namespace std;

int main() {
    int _;
    cin >> _;

    while (_--) {
        int n;
        cin >> n;

        pair<double, double> pos = {0, 0};
        double heading = 0;

        for (int i = 0; i < n; i++) {
            string cmd;
            cin >> cmd;

            double arg;
            cin >> arg;
            if (cmd == "fd") {
                pos.first += arg * cos(heading * M_PI / 180.0);
                pos.second += arg * sin(heading * M_PI / 180.0);
            } else if (cmd == "bk") {
                pos.first -= arg * cos(heading * M_PI / 180.0);
                pos.second -= arg * sin(heading * M_PI / 180.0);
            } else if (cmd == "lt") {
                heading += arg;
            } else {
                heading -= arg;
            }
        }

        double dist = sqrt(pos.first * pos.first + pos.second * pos.second);
        cout << (int) round(dist) << "\n";
    }
}