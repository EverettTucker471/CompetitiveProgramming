#include<vector>
#include<iostream>
#include<unordered_map>
#include<map>
#include<unordered_set>
#include<set>
#include<cmath>
#include<climits>
#include <algorithm>

using namespace std;

void a14() {
    int _;
    cin >> _;

    while (_--) {
        int l, r, d, u;
        cin >> l >> r >> d >> u;

        cout << ((l == r && r == d && d == u && d == l) ? "YES" : "NO") << endl;
    }
}

/*
int main() {
    a14();
    return 0;
}
 */