#include<vector>
#include<iostream>
#include<unordered_map>
#include<map>
#include<unordered_set>
#include<set>
#include<cmath>
#include <algorithm>

using namespace std;

void joint_jog_jam() {
    pair<int, int> a_s, a_e, b_s, b_e;
    cin >> a_s.first >> a_s.second;
    cin >> b_s.first >> b_s.second;
    cin >> a_e.first >> a_e.second;
    cin >> b_e.first >> b_e.second;

    double a = pow(a_s.first - b_s.first, 2) + pow(a_s.second - b_s.second, 2);
    double b = pow(a_e.first - b_e.first, 2) + pow(a_e.second - b_e.second, 2);

    printf( "%.10lf\n", sqrt(max(a, b)));
}