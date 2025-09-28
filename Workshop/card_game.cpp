#include <iostream>
#include <string>
#include <algorithm>
#include <vector>


// Oh, crucial misreading.
// The cards have to be of the same suit

using namespace std;

char trump;

bool compare(const string& a, const string& b) {
    // Returns true if a is larger
    if (a[1] == trump) {
        if (b[1] == trump) {
            return a[0] < b[0];
        } else {
            return false;
        }
    } else {
        if (b[1] == trump) {
            return true;
        } else {
            return a[0] < b[0];
        }
    }
}

void card_game() {
    int _;
    cin >> _;

    while (_--) {
        int n;
        cin >> n;
        cin >> trump;

        string arr[2 * n];
        for (string& x : arr) {
            cin >> x;
        }

        std::sort(arr, arr + 2 * n, compare);

        vector<string> smaller(n);
        vector<string> larger(n);

        bool works = true;
        for (int i = 0; i < n; i++) {
            if (compare(arr[i], arr[i + n])) {
                smaller[i] = arr[i];
                larger[i] = arr[i + n];
            } else {
                works = false;
                break;
            }
        }

        if (works) {
            for (int i = 0; i < n; i++) {
                cout << smaller[i] << " " << larger[i] << endl;
            }
        } else {
            cout << "IMPOSSIBLE" << endl;
        }
    }
}