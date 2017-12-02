#include "HoareMedianOf3IndexStrategy.h"

int HoareMedianOf3IndexStrategy::getStartPivotIndex(int start, int end)
{
    vector<int>& storage = this->getStorage();

    int middle = start + ((end - start) >> 1);

    if (storage[start] > storage[end]) {
        swap(storage[start], storage[end]);
    }

    if (storage[start] > storage[middle]) {
        swap(storage[start], storage[middle]);
    }
    else if (storage[middle] > storage[end]) {
        swap(storage[middle], storage[end]);
    }

    return middle;
}
