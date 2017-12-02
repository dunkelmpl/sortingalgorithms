#include "BaseStrategy.h"

BaseStrategy::BaseStrategy(BaseStrategy& bs)
{
    this->sortInstance = bs.sortInstance;
}

vector<int>& BaseStrategy::getStorage()
{
    return this->sortInstance->getStorage();
}

void BaseStrategy::setQuickSortInstance(QuickSort* const sortInstance)
{
    this->sortInstance = sortInstance;
}
