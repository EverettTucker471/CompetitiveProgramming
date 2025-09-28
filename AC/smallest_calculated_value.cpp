#include <iostream>
#include <vector>
#include <climits>

using namespace std;

void smallest_calculated_value() {
    int a, b, c;
    cin >> a >> b >> c;

    vector<int> res;
    res.push_back((a + b) + c);
    res.push_back((a + b) - c);
    res.push_back((a + b) * c);
    if ((a + b) % c == 0) {res.push_back((a + b) / c);}
    res.push_back((a - b) + c);
    res.push_back((a - b) - c);
    res.push_back((a - b) * c);
    if ((a - b) % c == 0) {res.push_back((a - b) / c);}
    res.push_back((a * b) + c);
    res.push_back((a * b) - c);
    res.push_back((a * b) * c);
    if ((a * b) % c == 0) {res.push_back((a * b) / c);}
    if (a % b == 0) {
        res.push_back((a / b) + c);
        res.push_back((a / b) - c);
        res.push_back((a / b) * c);
        if ((a / b) % c == 0) {
            res.push_back((a / b) / c);
        }
    }

    int min = INT_MAX;
    for (auto x : res) {
        if (x >= 0) {
            min = std::min(min, x);
        }
    }

    cout << min << endl;
}