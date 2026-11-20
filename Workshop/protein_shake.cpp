#include <bits/stdc++.h>

using namespace std;

int main() {
    // Max heap and min heap 

    long n, buffness, shakes;
    cin >> n >> buffness >> shakes;  // # competitiors, our buffness, our shakes

    map<long, vector<long>> bts;
    for (int i = 0; i < n; i++) {
        long b, s;
        cin >> b >> s;
        b = buffness - b;  // want them to be increasing
        if (bts.count(b)) {
            bts[b].push_back(s);
        } else {
            bts[b] = {s};
        }
    }

    priority_queue<long> max_heap;
    priority_queue<long, vector<long>, greater<long>> min_heap;

    // Putting begin iterator to the first positive advantage
    auto iter = bts.end();
    for (auto it = bts.begin(); it != bts.end(); it++) {
        if (it->first > 0) {
            iter = it;
            break;
        }
    }

    int heap_size;
    while (iter != bts.end()) {
        heap_size = iter->first;  // Our advantage
        for (long shakes : iter->second) {
            max_heap.push(shakes);
        }

        // Filling the max heap
        while (!max_heap.empty() && min_heap.size() < heap_size) {
            min_heap.push(max_heap.top());
            max_heap.pop();
        }

        // Moving bigger items from the max heap to the min heap
        while (!min_heap.empty() && !max_heap.empty() && min_heap.top() < max_heap.top()) {
            long big_shake = max_heap.top();
            long small_shake = min_heap.top();
            min_heap.pop();
            max_heap.pop();
            min_heap.push(big_shake);
            max_heap.push(small_shake);
        }
    }

    long final_buffness = buffness;
    int counter = 0;
    while (!min_heap.empty()) {
        final_buffness += max(min_heap.top() - counter, 0);
        min_heap.pop();
        counter++;
    }

}