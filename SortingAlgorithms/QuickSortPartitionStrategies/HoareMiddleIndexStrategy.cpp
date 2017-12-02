#include "HoareMiddleIndexStrategy.h"

int HoareMiddleIndexStrategy::getStartPivotIndex(int start, int end)
{
    return start + ((end - start) >> 1);
}
