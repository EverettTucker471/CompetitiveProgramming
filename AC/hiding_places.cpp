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
#include <queue>
#include <deque>

using namespace std;

vector<pair<int, int>> moves(pair<int, int> input) {
    vector<pair<int, int>> temp, rtn;
    temp.push_back({input.first + 1, input.second + 2});
    temp.push_back({input.first + 1, input.second - 2});
    temp.push_back({input.first - 1, input.second + 2});
    temp.push_back({input.first - 1, input.second - 2});
    temp.push_back({input.first + 2, input.second + 1});
    temp.push_back({input.first + 2, input.second - 1});
    temp.push_back({input.first - 2, input.second + 1});
    temp.push_back({input.first - 2, input.second - 1});

    for (auto x : temp) {
        if (x.first >= 0 && x.first < 8 && x.second >= 0 && x.second < 8) {
            rtn.push_back(x);
        }
    }

    return rtn;
}

int get(pair<int, int> move, const vector<vector<int>>& board) {
    return board[move.first][move.second];
}

void hiding_places() {
    int _;
    cin >> _;

    while (_--) {
        char c;
        int n;
        cin >> c;
        cin >> n;

        vector<vector<int>> board(8, vector<int>(8, INT_MAX));
        queue<pair<int, int>> queue;
        queue.push({(int) c - 'a', n - 1});

        board[queue.front().first][queue.front().second] = 0;
        while (!queue.empty()) {
            auto node = queue.front();
            queue.pop();
            
            for (auto k : moves(node)) {
                if (board[k.first][k.second] == INT_MAX) {
                    queue.push(k);
                }
                board[k.first][k.second] = min(board[node.first][node.second] + 1, board[k.first][k.second]);
            }
        }

        int top = 0;
        for (auto x : board) {
            for (auto y : x) {
                top = max(top, y);
            }
        }

        vector<pair<int, int>> rtn;
        for (int j = 7; j >= 0; j--) {
            for (int i = 0; i < 8; i++) {
                if (board[i][j] == top) {
                    rtn.push_back({i, j});
                }
            }    
        }
        

        cout << top << " ";
        for (auto x : rtn) {
            cout << ((char) (x.first + 'a')) << (x.second + 1) << " ";
        }
    }
}