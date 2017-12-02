#pragma once
#include "BaseStrategy.h"

class HoareBaseStrategy : public BaseStrategy
{
public:
    using BaseStrategy::BaseStrategy;

protected:
    int partition(int left, int right);

protected:
    virtual int getStartPivotIndex(int start, int end) = 0;
};
