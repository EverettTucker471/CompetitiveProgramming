#include <bits/stdc++.h>

using namespace std;

long n, m, k, finish, c;
vector<long> special;
vector<bool> visited;
vector<long> racers;
vector<long> racer_times;
vector<vector<long>> adj;
vector<priority_queue<vector<long>, vector<vector<long>>>> pqs;

void dfs(long u, long special_parent, long dist_to_parent) {
    int special_parent_save = special_parent;
    int distance_save = dist_to_parent;

    if (special[u]) {
        dist_to_parent = 0;
        special_parent = u;
    }

    for (long v : adj[u]) {
        if (!visited[v]) {
            visited[v] = true;
            dfs(v, special_parent, dist_to_parent + 1);
        }
    }

    // Propagating the racer
    if (racers[u] >= 0) {
        pqs[special_parent].push({
            dist_to_parent * racer_times[racers[u]],
            racer_times[racers[u]],
            racers[u]
        });
        if (special_parent != finish && pqs[special_parent].size() > k) {
            pqs[special_parent].pop();
        }
    }

    // Propagating everything at the special node, if it exists
    if (special[u]) {
        while (!pqs[u].empty()) {
            auto rt = pqs[u].top();
            pqs[u].pop();
            pqs[special_parent_save].push({
                rt[0] + distance_save * rt[1],
                rt[1],
                rt[2]
            });
            if (special_parent_save != finish && pqs[special_parent_save].size() > k) {
                pqs[special_parent_save].pop();
            }
        }
    }
}

int main() {
    cin >> n >> m >> k;
    adj.assign(n, vector<long>());

    for (long i = 0; i < n - 1; i++) {
        long u, v;
        cin >> u >> v;
        u--;
        v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    racers.assign(n, -1);
    racer_times.reserve(m);
    for (long i = 0; i < m; i++) {
        long p, t;
        cin >> p >> t;
        racers[p - 1] = i;
        racer_times[i] = t;
    }

    cin >> finish >> c;
    finish--;

    special.assign(n, false);
    for (long i = 0; i < c; i++) {
        long x;
        cin >> x;
        special[x - 1] = true;
    }

    pqs.assign(n, priority_queue<vector<long>, vector<vector<long>>>());
    visited.assign(n, false);
    visited[finish] = true;
    dfs(finish, finish, 0);

    vector<long> finish_times(m, -1);
    auto finish_pq = pqs[finish];
    while (!finish_pq.empty()) {
        vector<long> rt = finish_pq.top();
        finish_pq.pop();
        finish_times[rt[2]] = rt[0];
    }

    for (long x : finish_times) cout << x << "\n";
}

