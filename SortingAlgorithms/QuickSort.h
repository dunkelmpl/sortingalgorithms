#pragma once
#include "BaseSort.h"
#include "InsertionSort.h"
#include "QuickSortPartitionStrategies/BaseStrategy.h"

class BaseStrategy;

class QuickSort : public BaseSort
{
public:
    QuickSort(BaseStrategy& ps);
    QuickSort(int input[], size_t size, BaseStrategy& ps);

public:
    void sort();

protected:
    void sortChunk(int left, int right);
    int partition(int left, int right);
    bool isPivotAutoSorted();

protected:
    void insertionSort(int left, int right);

private:
    inline bool shouldUseInsertionSort(int left, int right);
    const int insSortUseThreshold = 7;
    BaseStrategy& partitionStrategy;
};
