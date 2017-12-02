#pragma once
#include "HoareBaseStrategy.h"

class HoareMiddleIndexStrategy : public HoareBaseStrategy
{
public:
    using HoareBaseStrategy::HoareBaseStrategy;

protected:
    int getStartPivotIndex(int start, int end);
};
