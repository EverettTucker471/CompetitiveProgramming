#include <bits/stdc++.h>
using namespace std;

int to_int(char c) {
    return (int) (c - '0');
}

int get_val(pair<char, char> p) {
    if (p.first == '1' && p.second == '2' || p.first == '2' && p.second == '1') {
        return 1000;
    } else if (p.first == p.second) {
        return to_int(p.first) * 100;
    } else {
        return to_int(max(p.first, p.second)) * 10 + to_int(min(p.first, p.second));
    }
}

bool check(pair<char, char> a, pair<char, char> b) {
    if (a.first != '*' && b.first != '*' && a.first != b.first) return false;
    if (a.second != '*' && b.second != '*' && a.second != b.second) return false;
    return true;
}

long gcd(long a, long b) {
    return (b == 0 ? a : gcd(b, a % b));
}

int main() {
    vector<pair<char, char>> pairs;
    vector<char> nums = {'1', '2', '3', '4', '5', '6'};
    for (char i : nums) {
        for (char j : nums) {
            pairs.emplace_back(i, j);
        }
    }

    vector<pair<int, int>> rtn;
    pair<char, char> a, b;
    while (cin >> a.first >> a.second >> b.first >> b.second) {
        if (a.first == '0') break;

        int numer = 0;
        int denom = 0;
        for (int i = 0; i < 36; i++) {
            for (int j = 0; j < 36; j++) {
                if (check(a, pairs[i]) && check(b, pairs[j])) {
                    denom++;
                    if (get_val(pairs[j]) < get_val(pairs[i])) {
                        numer++;
                    }
                }
            }
        }

        rtn.emplace_back(numer, denom);
    }

    for (auto p : rtn) {
        long g = gcd((long) p.first, (long) p.second);
        if (p.first == 0) {
            cout << "0\n";
        } else if (p.first == p.second) {
            cout << "1\n";
        } else {
            cout << p.first / g << '/' << p.second / g << '\n';            
        }
    }
}