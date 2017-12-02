#pragma once
#include "HoareBaseStrategy.h"

class HoareMedianOf3IndexStrategy : public HoareBaseStrategy
{
public:
    using HoareBaseStrategy::HoareBaseStrategy;

protected:
    int getStartPivotIndex(int start, int end);
};
