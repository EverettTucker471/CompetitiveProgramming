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

// Evaluates the integrated polynomial
double evalPoly(const vector<double>& a, double x) {
    double rtn = 0;
    double power = x;
    for (double val : a) {
        rtn += val * power;
        power *= x;
    }
    return rtn;
}

double searchForHeight(const vector<double>& a, double val) {

}

void bottles() {
    /*
     * Integrate the polynomial and multiply by pi to
     * get a function for volume in terms of height
     * Successively binary search on height to get markings
     */

    int index = 0;
    int n;
    while (cin >> n) {
        index++;
        n++;
        double a[n];
        for (auto& x : a) cin >> x;

        double low, high;
        int inc;
        cin >> low >> high >> inc;

        // Squaring the function and multiplying by pi
        vector<double> a2(2 * n + 1);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                a2[i + j] += a[i] * a[j] * M_PI;
            }
        }

        // Integrating
        for (int i = 0; i < 2 * n + 1; i++) a2[i] /= (i + 1);

        // Printing volume
        double volume = evalPoly(a2, high) - evalPoly(a2, low);
        cout << "Case " << index << ": " << volume << endl;

        if (volume > inc) {
            cout << "insufficient volume" << endl;
        } else {
            int val = inc;
            while (val <= volume) {
                cout << searchForHeight(a2, val) << " ";
            }
            cout << endl;
        }

        cout << evalPoly(a2, high) - evalPoly(a2, low) << endl;
    }
}

int main(){
    bottles();
    return 0;
}