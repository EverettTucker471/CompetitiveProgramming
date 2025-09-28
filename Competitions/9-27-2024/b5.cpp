#include <iostream>
#include <unordered_map>
using namespace std;


/**
 * There are n(n - 1)/2 segments total
 * We know that every interval [a, b] exists where a, b in arr
 * For a given x, the number of intervals it's in is equal to the number
 * of a <= x times the number of a >= x.
 * Cannot precompute for all x
 * This is a factoring problem, we wish to factor q, then sum
 * arr[i + 1] - arr[i] where i is a factor of q
 *
 * Finally figured out the precomputation step, time to implement
 *
 * Passes up to test 9, I can't find the error though
 * I have zero clue what it could be
 */
void b5() {
    int _;
    cin >> _;

    while (_--) {
        int n, q;
        cin >> n >> q;
        int arr[n];
        for (auto& x : arr) {cin >> x;}

        // Precomputation
        unordered_map<long long int, int> answers;
        for (int i = 0; i < n; i++) {
            if (i + 1 < n) {
                answers[(i + 1) * (n - i - 1)] += arr[i + 1] - arr[i] - 1;
            }
            answers[i + (i + 1) * (n - i - 1)]++;
        }

        /*
        for (auto x : answers) {
            cout << x.first << " " << x.second << endl;
        }
        cout << endl;
        */

        while (q--) {
            long long int x;
            cin >> x;

            if (answers.count(x)) {
                cout << answers.at(x) << " ";
            } else {
                cout << 0 << " ";
            }
        }
        cout << endl;
    }
}