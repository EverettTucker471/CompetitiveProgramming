#include<vector>
#include<iostream>
#include<unordered_map>
#include<map>
#include<unordered_set>
#include<set>
#include<cmath>
#include <algorithm>
#include <climits>
#include <numeric>

using namespace std;

void game_of_throwns() {
    int n, k;
    cin >> n >> k;

    string temp;
    vector<int> stack;
    while (k--) {
        int command;
        if (cin >> command) {
            stack.push_back(command);
        } else {
            cin.clear();
            cin >> temp;  // Unused, clearing buffer
            int undo;
            cin >> undo;
            while (undo--) stack.pop_back();
        }
    }

    int sum = 0;
    for (auto x : stack) sum += x;
    // for (auto x : stack) cout << x << " ";

    cout << ((sum % n) + n) % n << endl;
}