#include<vector>
#include<iostream>
#include<unordered_map>
#include<map>
#include<unordered_set>
#include<set>
#include<cmath>
#include <algorithm>

using namespace std;

void pathless() {
    int _;
    cin >> _;

    while (_--) {
        int n, s;
        cin >> n >> s;
        int quant[] = {0, 0, 0};
        int sum = 0;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            sum += x;
            quant[x]++;
        }


        // Just check if the sorted array is possible
        if (sum > s) {
            // Anything works
            // Arrange 0s first, then 2s, then 1s
            while (quant[0]--) {
                cout << 0 << " ";
            }
            while (quant[2]--) {
                cout << 2 << " ";
            }
            while (quant[1]--) {
                cout << 1 << " ";
            }
        } else if (sum == s) {
            cout << -1;
        } else if (sum + 1 == s) {
            // Arrange 0s first, then 2s, then 1s
            while (quant[0]--) {
                cout << 0 << " ";
            }
            while (quant[2]--) {
                cout << 2 << " ";
            }
            while (quant[1]--) {
                cout << 1 << " ";
            }
        } else {
            cout << -1;
        }
        cout << endl;
    }
}