#pragma once
#include "BaseSort.h"
#include "InsertionSort.h"

class QuickSort : public BaseSort
{
public:
    using BaseSort::BaseSort;

public:
    void sort();

protected:
    void sortChunk(int left, int right);
    int partition(int left, int right);

protected:
    void insertionSort(int left, int right);

private:
    inline bool shouldUseInsertionSort(int left, int right);
    const int insSortUseThreshold = 7;
};
