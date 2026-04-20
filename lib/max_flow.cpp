#include <bits/stdc++.h>

using namespace std;

int n;
vector<vector<int>> adj;  // Adjacency list
/**
 * Initially, this is the capacity of the edge from i to j
 * During the algorithm, it stores the residual capacity,
 * the difference between the max and the actual flow
 */
vector<vector<long>> cap;  

/**
 * BFS helper function for max flow
 * @param s the index of the source vertex
 * @param t the index of the sink vertex
 * @param parent an array of parent indices
 * @return 
 */
int bfs(int s, int t, vector<int>& parent) {
    fill(parent.begin(), parent.end(), -1);
    parent[s] = -2;
    queue<pair<int, long>> q;
    q.emplace(s, LONG_MAX);

    while (!q.empty()) {
        int cur = q.front().first;
        long flow = q.front().second;
        q.pop();

        for (int next : adj[cur]) {
            if (parent[next] == -1 && cap[cur][next]) {
                parent[next] = cur;
                long new_flow = min(flow, cap[next][cur]);
                if (next == t) return new_flow;
                q.emplace(next, new_flow);
            }
        }
    }

    return 0;
}

/**
 * Implements Edmond-Karp to solve the max flow problem
 * Runs in O(VE^2)
 * @param s the index of the source vertex
 * @param t the index of the sink vertex
 * @return the maximum flow achievable through the graph
 */
int max_flow(int s, int t) {
    long flow = 0;
    vector<int> parent(n);
    long new_flow;

    while (new_flow = bfs(s, t, parent)) {
        flow += new_flow;
        int cur = t;
        while (cur != s) {
            int prev = parent[cur];
            cap[prev][cur] -= new_flow;
            cap[cur][prev] += new_flow;
            cur = prev;
        }
    }

    return flow;
}