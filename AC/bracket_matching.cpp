#include <string>
#include <iostream>
#include <stack>
#include <unordered_map>

using namespace std;

unordered_map<char, char> map{{'}', '{'}, {')', '('}, {']', '['}};

void bracket_matching() {
    int n;
    string s;
    cin >> n;
    cin >> s;

    stack<char> stack;

    for (int i = 0; i < n; i++) {
        if (!stack.empty() && stack.top() == map[s[i]]) {
            stack.pop();
        } else {
            stack.push(s[i]);
        }
    }

    cout << (stack.empty() ? "Valid" : "Invalid");
}