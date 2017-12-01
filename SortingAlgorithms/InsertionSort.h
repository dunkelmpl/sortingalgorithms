#pragma once
#include "BaseSort.h"

class InsertionSort : public BaseSort
{
public:
    using BaseSort::BaseSort;

public:
    void sort();
    void sort(vector<int>& customStorage, int start = 0, int end = -1);
};

