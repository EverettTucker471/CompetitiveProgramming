#include<iostream>
#include<cmath>

using namespace std;

int building_highways() {
    int n;
    cin >> n;
    
    int a[n];
    for (auto& x : a) cin >> x;
    
    long long sum = 0;
    long long min = a[0];
    for (int x : a) {
        min = std::min((long long) x, min );
        sum += x;
    }
    
    cout << (sum + (n - 2) * min) << endl;
}

int main() {
    building_highways();
    return 0;
}