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
#include <deque>
    
using namespace std;
    
void b22() {
    int _;
    cin >> _;
    
    while (_--) {
        int n, k;
        cin >> n >> k;
    
        int top = 0;
        int bottom = 0;
        int question = 0;
        for (int i = 0; i < k; i++) {
            char c;
            cin >> c;
            if (c == '0') {
                top++;
            } else if (c == '1') {
                bottom++;
            } else {
                question++;
            }
        }
    
        string rtn = "";
        int i = 0;
        for (; i < top; i++) rtn += '-';
    
        if (question != n - (top + bottom)) {
            if (n - (top + bottom) - 2 * question < 0) {
                for (; i < n - bottom; i++) rtn += '?';
            } else {
                for (; i < top + question; i++) rtn += '?';
                for (; i < n - bottom - question; i++) rtn += '+';
                for (; i < n - bottom; i++) rtn += '?';
            }
        }   
        
        for (; i < n; i++) rtn += '-';
    
        cout << rtn << endl;
    }
}