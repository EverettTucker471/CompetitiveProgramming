#include <bits/stdc++.h>

using namespace std;

int n, k, d, s;
vector<long> p;
vector<int> perm;
vector<long> values;

long row(int i) {
    // Row of length s starting at index i
    int j = (i + s - 1) % n;
    if (i > j) {
        return p[j + 1] + p[n] - p[i];
    } else {
        return p[j + 1] - p[i];
    }
}

long rect(int i) {
    // Computes the sum of a rectangle of size d x s starting at index i
    long sum = 0;
    for (int idx = 0; idx < d; idx++) {
        sum += row(i);
        i = (i + k) % n;
    }
    return sum;
}

long gcd(long long a, long long b) {
    return (b == 0 ? a : gcd(b, a % b));
}

void fill_in(int top_idx, int iter) {
    int bot_idx = top_idx;
    long sliding_sum = 0;
    for (int i = 0; i < d; i++) {
        sliding_sum += row(bot_idx);
        bot_idx = (bot_idx + k) % n;
    }
    values[top_idx] = sliding_sum;
    for (int i = d; i < iter + d - 1; i++) {
        sliding_sum -= row(top_idx);
        sliding_sum += row(bot_idx);
        top_idx = (top_idx + k) % n;
        bot_idx = (bot_idx + k) % n;
        values[top_idx] = sliding_sum;
        cout << top_idx << endl;
    }
}

int main() {
    cin >> n >> k >> d >> s;
    k %= n;

    vector<int> a(n);
    for (auto& x : a) cin >> x;

    p.assign(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        p[i] = p[i - 1] + a[i - 1];
    }

    // Filling in all the values
    values.assign(n, 0);
    // Start a index 0
    long g = gcd(n, k);
    for (int i = 0; i < g; i++) {
        fill_in(i, n / g);
    }
    

    for (auto x : values) {
        cout << x << " ";
    }
}