#pragma once
#include "../QuickSort.h"

class QuickSort;

class BaseStrategy
{
public:
    BaseStrategy() : sortInstance(nullptr) {}
    BaseStrategy(BaseStrategy& bs);
    
    virtual ~BaseStrategy() {};

public:
    void setQuickSortInstance(QuickSort* const sortInstance);
    virtual int partition(int left, int right) = 0;
    inline virtual bool isPivotAutoSorted() { return false; }

protected:
    vector<int>& getStorage();

protected:
    QuickSort* sortInstance = nullptr;
};
