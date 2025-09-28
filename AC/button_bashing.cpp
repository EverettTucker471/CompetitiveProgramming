#include<vector>
#include<iostream>
#include<unordered_map>
#include<map>
#include<unordered_set>
#include<set>
#include<cmath>
#include <algorithm>
#include <queue>
#include <climits>

using namespace std;

const int LEN = 3601;

void button_bashing() {
    int _;
    cin >> _;

    while (_--) {
        int n, t;
        cin >> n >> t;
        int a[n];
        for (auto& x : a) cin >> x;

        vector<int> dist(LEN, INT_MAX);
        dist[0] = 0;
        queue<int> q;
        q.push(0);

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            for (int x : a) {
                int temp = min(max(0, node + x), LEN - 1);
                if (dist[node] + 1 < dist[temp]) {
                    q.push(temp);
                    dist[temp] = dist[node] + 1;
                }
            }
        }

        for (int i = t; i < LEN; i++) {
            if (dist[i] < INT_MAX) {
                cout << dist[i] << " " << i - t << endl;
                break;
            }
        }
    }
}