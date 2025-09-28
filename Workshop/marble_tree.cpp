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

void marble_tree() {
    int n;
    cin >> n;
    while (n > 0) {
        // There is a total of n marbles
        vector<vector<int>> adj(n, vector<int>());
        int marbles[n];
        for (int i = 0; i < n; i++) {
            int x, d;
            cin >> x;
            cin >> marbles[x - 1];
            cin >> d;
            while (d--) {
                int y;
                cin >> y;
                adj[x - 1].push_back(y);
            }
        }







        cin >> n;
    }
}