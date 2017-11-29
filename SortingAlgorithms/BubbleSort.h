#pragma once
#include "AbstractSort.h"

class BubbleSort : public AbstractSort
{
public:
    void sort();
protected:
    inline void swap(int& item1, int& item2);
};
