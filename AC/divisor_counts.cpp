#include <iostream>
#include <vector>

using namespace std;

/*
void divisor_counts() {
    int n;
    cin >> n;

    vector<int> rtn(n + 1, 1);

    for (int i = 2; i <= n; i++) {
        int w = i;
        unordered_map<int, int> f;
        for (int j = 2; j * j <= w; j++) {
            if (w % j == 0) {
                f[j]++;
                w /= j;
                j = 1;
            }
        }
        // Adding the final prime number
        f[w]++;

        for (auto x : f) {
            rtn[i] *= (x.second + 1);
        }
        cout << endl;
    }

    for (int i = 1; i <= n; i++) cout << rtn[i] << endl;
}
*/

void dp_method() {
    int n;
    cin >> n;

    vector<int> rtn(n + 1, 1);
    vector<int> primes;
    for (int i = 2; i <= n; i++) {
        int w = i;
        int factor = -1;
        for (int j : primes) {
            if (j * j > w) break;
            if (w % j == 0) {
                factor = j;
                break;
            }
        }

        if (factor == -1) {
            primes.push_back(w);
            rtn[i] = 2;
        } else {
            int count = 1;
            while (w % factor == 0) {
                w /= factor;
                count++;
            }
            rtn[i] = rtn[w] * count;
        }
    }

    for (int i = 1; i <= n; i++) printf("%d\n", rtn[i]);
}

/*
void seive() {
    int n;
    cin >> n;

    vector<int> seive(n + 1, 1);
    for (int i = 2; i <= n; i++) {
        for (int j = i; j <= n; j += i) {
            seive[j]++;
        }
    }

    for (int i = 1; i <= n; ++i) printf("%d\n", seive[i]);
}
*/