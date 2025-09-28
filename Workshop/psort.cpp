#include <iostream>

bool DFS(int i, int want, int n, int a[], int explored[]) {
    if (i + 1 == want) {return true;}
    explored[i] = 1;

    bool x = false;
    bool y = false;

    if (i - a[i] >= 0 && !explored[i - a[i]]) {
        x = DFS(i - a[i], want, n, a, explored);
    }
    if (i + a[i] < n && !explored[i + a[i]]) {
        y = DFS(i + a[i], want, n, a, explored);
    }

    return x || y;
}


void pSort() {
    int n = 0;
    std::cin >> n;
    int a[n];
    int b[n];
    for (int& x : a) {std::cin >> x;}
    for (int& x : b) {std::cin >> x;}

    for (int i = 0; i < n; i++) {
        int explored[n];
        for (int& x : explored) {x = 0;}
        if (!DFS(i, b[i], n, a, explored)) {
            std::cout << "NO" << std::endl;
        } else {
            std::cout << "YES" << std::endl;
        }
    }
    std::cout << "YES" << std::endl;
}
