#include <bits/stdc++.h>

using namespace std;

int ans;
vector<int> tree;

void traverse(int i) {
    if (tree[i] == -1) {
        int left = 2 * i + 1;
        int right = left + 1;
        if (tree[left] == -1) traverse(left);
        if (tree[right] == -1) traverse(right);
        if (tree[left] == tree[right] && tree[left] != -1) {
            tree[i] = tree[left];
        } else {
            tree[i] = -1;
        }
    }
}

void count(int i, int length) {
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (right < length) {
        if (tree[left] == tree[right] && tree[left] != -1) {
            ans -= 2;
        }
        count(left, length);
        count(right, length);
    }
}

int main() {
    int n;
    cin >> n;

    int len = pow(2, n);
    vector<int> arr(len);
    for (int i = 0; i < len; i++) {
        cin >> arr[i];
    }

    // -1 is the sentinel value
    tree.assign(2 * len - 1, -1);

    // Creating the tree
    for (int i = 0; i < len; i++) {
        int tree_idx = 0;
        int num = i;

        // Going down the tree reading digits from the right
        for (int j = 0; j < n; j++) {
            tree_idx *= 2;
            if (num % 2) {
                tree_idx += 2;
            } else {
                tree_idx += 1;
            }
            num /= 2;
        }
        tree[tree_idx] = arr[i];
    }

    ans = 2 * len - 1;
    traverse(0);
    count(0, 2 * len - 1);
    cout << ans << '\n';
}
