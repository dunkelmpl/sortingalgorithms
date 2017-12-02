#pragma once
#include "HoareBaseStrategy.h"

class HoareRandomIndexStrategy : public HoareBaseStrategy
{
public:
    using HoareBaseStrategy::HoareBaseStrategy;

protected:
    int getStartPivotIndex(int start, int end);
};
