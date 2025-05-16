#include "sorts_simple.h"
#include <algorithm>

void bubbleSort(int *ar, int size)
{
    for (int i = 0; i < size - 1; ++i)
        for (int j = 0; j < size - i - 1; ++j)
            if (ar[j] > ar[j + 1])
                std::swap(ar[j], ar[j + 1]);
}

void insertionSort(int *ar, int size)
{
    for (int i = 1; i < size; ++i)
    {
        int key = ar[i], j = i - 1;
        while (j >= 0 && ar[j] > key)
            ar[j + 1] = ar[j--];
        ar[j + 1] = key;
    }
}

void selectionSort(int *ar, int size)
{
    for (int i = 0; i < size - 1; ++i)
    {
        int min_idx = i;
        for (int j = i + 1; j < size; ++j)
            if (ar[j] < ar[min_idx])
                min_idx = j;
        std::swap(ar[min_idx], ar[i]);
    }
}

// Вспомогательные функции для quickSort
int partition(int *ar, int low, int high)
{
    int pivot = ar[high], i = low - 1;
    for (int j = low; j < high; ++j)
        if (ar[j] < pivot)
            std::swap(ar[++i], ar[j]);
    std::swap(ar[i + 1], ar[high]);
    return i + 1;
}
void quickSortRec(int *ar, int low, int high)
{
    if (low < high)
    {
        int pi = partition(ar, low, high);
        quickSortRec(ar, low, pi - 1);
        quickSortRec(ar, pi + 1, high);
    }
}
void quickSort(int *ar, int size)
{
    quickSortRec(ar, 0, size - 1);
}

// MergeSort
void merge(int *ar, int l, int m, int r)
{
    int n1 = m - l + 1, n2 = r - m;
    int *L = new int[n1], *R = new int[n2];
    for (int i = 0; i < n1; i++)
        L[i] = ar[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = ar[m + 1 + j];

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2)
        ar[k++] = (L[i] <= R[j]) ? L[i++] : R[j++];
    while (i < n1)
        ar[k++] = L[i++];
    while (j < n2)
        ar[k++] = R[j++];

    delete[] L;
    delete[] R;
}
void mergeSortRec(int *ar, int l, int r)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;
        mergeSortRec(ar, l, m);
        mergeSortRec(ar, m + 1, r);
        merge(ar, l, m, r);
    }
}
void mergeSort(int *ar, int size)
{
    mergeSortRec(ar, 0, size - 1);
}
