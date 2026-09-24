#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> guess;
vector<int> ground_truth = {7, 8, 5, 3, 4, 6, 9, 10, 2, 1};

int send_guess() {
    int rtn = 0;
    for (int i = 0; i < ground_truth.size(); i++) {
        if (ground_truth[i] == guess[i]) rtn++;
    }
    return rtn;
}

// int send_guess() {
//     for (int x : guess) cout << x << " ";
//     cout << endl;

//     int rtn;
//     cin >> rtn;

//     // Exiting if everything is right
//     if (rtn == n) {
//         for (int x : guess) cout << x << " ";
//         cout << endl;
//         exit(0);
//     }
//     return rtn;
// }

void swap(int i, int j) {
    int temp = guess[i];
    guess[i] = guess[j];
    guess[j] = temp;
}

void three_way_shuffle(int i, int j, int k) {
    vector<vector<int>> orderings = {
        {i, j, k},
        {i, k, j},
        {j, i, k},
        {j, k, i},
        {k, i, j},
        {k, j, i}
    };

    int best_val = -1;
    vector<int> best;
    for (vector<int> order : orderings) {
        int temp = guess[order[0]];
        guess[order[0]] = guess[order[1]];
        guess[order[1]] = guess[order[2]];
        guess[order[2]] = temp;
        int val = send_guess();
        if (val > best_val) {
            best_val = val;
            best = guess;
        }
    }

    guess = best;
}

int main() {
    cin >> n;

    // Sending the initial guess
    for (int i = 0; i < n; i++) guess.push_back(i + 1);

    int diff;
    int baseline = send_guess();

    pair<int, int> plus_ones = {-1, -1};
    // Finding at least one bottle that's correct
    for (int i = 1; i < n; i++) {
        swap(0, i);
        diff = send_guess() - baseline;

        if (diff == 2) {
            // Two WEREN'T correct and now they are
            break;
        } else if (diff == -2) {
            // Two WERE correct and now they aren't
            swap(0, i);
            break;
        } else if (diff == 1) {
            // At least one of index 0 or i WAS correct
            if (plus_ones.first != -1) {
                plus_ones.second = i;
                swap(0, i); // Swapping back
                break;
            } else {
                plus_ones.first = i;
            }
        }

        swap(0, i);  // Swapping back
    }

    if (plus_ones.second != -1) {
        // perform the 3-way shuffling
        three_way_shuffle(0, plus_ones.first, plus_ones.second);
    }

    // At this point, we should be able to guarantee that the first index is correct

    for (auto x : guess) cout << x << " ";
    cout << endl;

    vector<bool> known_correct(n, false);
    known_correct[0] = true;
    for (int i = 0; i < n; i++) {
        baseline = send_guess();
        for (int j = i + 1; j < n; j++) {
            swap(i, j);
            diff = send_guess() - baseline;
            
            if (known_correct[i]) {
                // We know that i is correct
                if (diff == -1) {
                    // J wasn't in the right spot
                } else if (diff == -2) {
                    // J was in the right spot
                    known_correct[j] = true;
                }
                swap(i, j);
            } else {
                // We know that i is incorrect
                if (diff == 2) {
                    // Both are now correct
                    known_correct[i] = true;
                    known_correct[j] = true;
                    break;
                } else if (diff == 1) {
                    
                } else {
                    swap(i, j);
                }
            }
        }
    }

    for (int x : guess) cout << x << " ";
    cout << endl;
}