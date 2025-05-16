#include <iostream>
#include <iomanip>
#include <random>
#include "sorts_simple.h"
#include "MeasTime.h"

int main()
{
    int sizes[] = {100, 500, 750, 900, 1400, 2000, 2500, 4100, 5000,
                   7800, 9500, 12000, 13000, 15000, 25000, 33000,
                   50000, 100000, 140000, 180000, 250000, 400000,
                   500000, 655000, 800000, 840000, 1000000};

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(0, 1000000);

    std::cout << "N\tBubble\tInsert\tSelect\tQuick\tMerge\n";

    for (int size : sizes)
    {
        int *array = new int[size];
        for (int i = 0; i < size; ++i)
            array[i] = dist(gen);

        std::cout << size << '\t';

        if (size <= 100000)
        {
            std::cout << std::fixed << std::setprecision(2)
                      << measureTime(bubbleSort, array, size) << '\t'
                      << measureTime(insertionSort, array, size) << '\t'
                      << measureTime(selectionSort, array, size) << '\t';
        }
        else
        {
            std::cout << "-\t-\t-\t";
        }

        std::cout << std::fixed << std::setprecision(2)
                  << measureTime(quickSort, array, size) << '\t'
                  << measureTime(mergeSort, array, size) << '\n';

        delete[] array;
    }

    return 0;
}
