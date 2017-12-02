#include "HoareRandomIndexStrategy.h"

int HoareRandomIndexStrategy::getStartPivotIndex(int start, int end)
{
    return (rand() % (end - start + 1)) + start;
}
