#include <bits/stdc++.h>

using namespace std;

struct Event {
    bool start;
    double x, y1, y2;

    bool operator<(const Event& right) const {
        return tie(x, y1) < tie(right.x, right.y1);
    }
};

vector<Event> events;

int main() {
    int n;
    cin >> n;

    events.assign(2 * n, {});
    for (int i = 0; i < n; i++) {
        double x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        events[2 * i] = {start: true, x1, y1, y2};
        events[2 * i + 1] = {start: false, x2, y1, y2};
    }
    sort(events.begin(), events.end());

    for (auto x : events) {
        cout << x.x << '\n';
    }
}