#pragma once
#include "BaseSort.h"

class QuickSort : public BaseSort
{
public:
    void sort();

protected:
    void sortChunk(int left, int right);
    int partition(int left, int right);
};
