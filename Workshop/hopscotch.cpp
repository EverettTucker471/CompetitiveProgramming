#include<vector>
#include<iostream>
#include<unordered_map>
#include<map>
#include<unordered_set>
#include<set>
#include<cmath>
#include <algorithm>
#include <queue>

using namespace std;

void hopscotch() {
    int n, k;
    cin >> n >> k;

    int arr[n][n];
    for (auto& x : arr) {
        for (auto& y : x) {
            cin >> y;
        }
    }

    bool visited[n][n];
    // Stores distance, (x, y) pairs
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, std::greater<>> pq;

}