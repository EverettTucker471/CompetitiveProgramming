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

void c15() {
    // This is fibonacci obviously
    int n;
    cin >> n;

    vector<int> fib;
    fib.push_back(0);
    fib.push_back(1);
    for (int i = 0; i < n - 1; i++) {
        fib.push_back(fib[fib.size() - 1] + fib[fib.size() - 2]);
    }

    cout << fib[n - 1] << " " << fib[n];
}