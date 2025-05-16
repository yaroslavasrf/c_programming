#include "dz1.h"
#include <iostream>

using namespace std;

int main() {
    int x[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    size_t y = sizeof(x) / sizeof(x[0]);

    ShowNum_reverse(x, y);
    ShowNum(x, y);
    ShowEven(x, y);

    return 0;
}