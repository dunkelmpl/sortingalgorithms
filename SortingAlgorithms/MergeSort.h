#pragma once
#include "BaseSort.h"

class MergeSort : public BaseSort
{
public:
    using BaseSort::BaseSort;

public:
    void sort();
protected:
    void sortChunk(size_t start, size_t end);
    void merge(size_t start, size_t middle, size_t end);
};

