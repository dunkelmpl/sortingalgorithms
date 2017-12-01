#pragma once
#include "MergeSort.h"

class IterativeMergeSort : public MergeSort
{
public:
    using MergeSort::MergeSort;

public:
    void sort();
};
