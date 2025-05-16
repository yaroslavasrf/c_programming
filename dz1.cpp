#include "dz1.h"
#include <iostream>

using namespace std;

void ShowNum_reverse(const int* x, size_t y) {
    for (size_t i = y; i > 0; i--) {
        cout << x[i - 1];
        if (i > 1) cout << '\t';
    }
    cout << '\n';
}

void ShowNum(const int* x, size_t y) {
    for (size_t i = 0; i < y; i++) {
        cout << x[i];
        if (i < y - 1) cout << '\t';
    }
    cout << '\n';
}

void ShowEven(const int* x, size_t y) {
    bool f = true;
    for (size_t i = 0; i < y; i++) {
        int n = x[i];
        if ((n / 2) * 2 == n) {
            if (!f) cout << '\t';
            cout << n;
            f = false;
        }
    }
    cout << '\n';
}