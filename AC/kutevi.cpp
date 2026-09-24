#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> have(n);
    vector<int> need(k);
    for (auto& x : have) cin >> x;
    for (auto& x : need) cin >> x;

    vector<bool> can_get(360, false);
    can_get[0] = true;
    
    for (int angle : have) {
        for (int i = 0; i < 360; i++) {
            if (can_get[i]) {
                for (int mult = 1; mult <= 360; mult++) {
                    can_get[(i + angle * mult) % 360] = true;
                }
            }
        }
    }

    for (int target : need) {
        cout << (can_get[target] ? "YES" : "NO") << '\n';
    }
}