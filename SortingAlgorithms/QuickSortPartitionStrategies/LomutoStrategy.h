#pragma once
#include "BaseStrategy.h"

class LomutoStrategy : public BaseStrategy
{
public:
    using BaseStrategy::BaseStrategy;
    virtual ~LomutoStrategy() {}

public:
    int partition(int left, int right);
    inline bool isPivotAutoSorted() { return true; }
};
