#include <iostream>
#include <vector>

using namespace std;

// This is O(nlong) using some type of binary searchDFS
// Probably start with one node and then find the paths radiating from that node
// Just use that node as the root
// Works I had some trouble with cout.flush()
void guess_the_tree() {
    int _;
    cin >> _;

    while (_--) {
        int n;
        cin >> n;
        pair<int, int> rtn[n - 1];

        for (int i = 2; i <= n; i++) {
            int node = 1;
            int val;
            while (true) {
                cout << "? " << node << " " << i << endl;
                cout.flush();
                cin >> val;

                if (val == node) {
                    rtn[i - 2] = {val, i};
                    break;
                }
                node = val;
            }
        }

        cout << "! ";
        for (auto x : rtn) {
            cout << x.first << " " << x.second << " ";
        }
    }
}