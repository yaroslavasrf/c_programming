#pragma once
#include <functional>

double measureTime(void (*sortFunc)(int *, int), int *array, int size);
