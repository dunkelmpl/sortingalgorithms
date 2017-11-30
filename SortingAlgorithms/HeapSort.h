#pragma once
#include "BaseSort.h"
class HeapSort :
    public BaseSort
{
public:
    void sort();

protected:
    void heapify();
    void siftDown(size_t top, size_t size);
};

