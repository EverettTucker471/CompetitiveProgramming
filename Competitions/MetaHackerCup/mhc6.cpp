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

void mhc6() {
    int _;
    cin >> _;

    for (int c = 1; c <= _; c++) {
        int n;
        cin >> n;
        string s;
        cin >> s;

        vector<int> ap(n + 1, 0);  // Bob's partials
        vector<int> bp(n + 1, 0);  // Alice's partials

        int count = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == 'A') {
                count++;
            } else {
                ap[i] = count;
                count = 0;
            }
        }
        // Ending the substring
        ap[n] = count;

        count = 0;
        for (int i = n; i > 0; i--) {
            if (s[i - 1] == 'B') {
                count++;
            } else {
                count = 0;
            }

            bp[i - 1] = std::max(bp[i], count);
        }

        bp.pop_back();

        // Idea?
        bool rtn = false;
        for (int i = 1; i <= n; i++) {
            if (ap[i] > 0 && ap[i] > bp[i - 1]) {
                rtn = true;
                break;
            }
        }

        if (rtn) {
            printf("Case %d: Alice\n", c);
        } else {
            printf("Case %d: Bob\n", c);
        }
            
        /*
        cout << "AP: ";
        for (auto x : ap) {
            cout << x << " ";
        }
        cout << endl;

        cout << "BP: ";
        for (auto x : bp) {
            cout << x << " ";
        }
        cout << endl;
        */
    }
}

int main() {
    mhc6();
    return 0;
}