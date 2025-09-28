#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

unordered_set<char> vow{'A', 'E', 'I', 'O', 'U'};
unordered_set<char> con{'B', 'C', 'D', 'F', 'G', 'H', 'J', 'K', 'L', 'M', 'N', 'P', 'Q', 'R', 'S', 'T', 'V', 'W', 'X', 'Y', 'Z'};

bool check(const string& s) {
    bool l = false;

    for (auto c : s) {
        if (c == 'L') {
            l = true;
            break;
        }
    }

    for (int i = 2; i < s.size(); i++) {
        if (vow.count(s[i - 2]) && vow.count(s[i - 1]) && vow.count(s[i])) {
            return false;
        }
        if (con.count(s[i - 2]) && con.count(s[i - 1]) && con.count(s[i])) {
            return false;
        }
    }

    return l;
}

// Assumes that there is an L in the input
long long int permute(const string& s) {
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '_') {
            // Either vowel, consonant, or L
            string t1 = s;
            t1[i] = 'A';
            long long int rtn = 0;
            rtn += 5 * permute(t1);
            string t2 = s;
            t2[i] = 'B';
            rtn += 20 * permute(t2);
            string t3 = s;
            t3[i] = 'L';
            rtn += permute(t3);
            return rtn;
        }
    }
    return check(s);
}

// There are only really 2^10 combinations, either vowel or not
void dobra() {
    string s;
    cin >> s;

    cout << permute(s) << endl;
}
