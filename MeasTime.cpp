#include "MeasTime.h"
#include <chrono>
#include <cstring>

double measureTime(void (*sortFunc)(int *, int), int *array, int size)
{
    int *temp = new int[size];
    std::memcpy(temp, array, size * sizeof(int));

    auto start = std::chrono::high_resolution_clock::now();
    sortFunc(temp, size);
    auto end = std::chrono::high_resolution_clock::now();

    delete[] temp;

    std::chrono::duration<double, std::milli> duration = end - start;
    return duration.count();
}
