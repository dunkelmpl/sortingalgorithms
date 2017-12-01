#include "QuickSort.h"

void QuickSort::sort()
{
    this->sortChunk(0, storage.size() - 1);
}

void QuickSort::sortChunk(int left, int right)
{
    if (left >= right) {
        return;
    }

    int pivot = this->partition(left, right);

    this->sortChunk(left, pivot - 1);
    this->sortChunk(pivot + 1, right);
}

int QuickSort::partition(int left, int right)
{
    int pvtPos = right;
    int newPvtPos = left;

    for (int pos = left; pos < right; pos++) {
        if (storage[pos] <= storage[pvtPos]) {
            swap(storage[pos], storage[newPvtPos]);
            newPvtPos++;
        }
    }

    swap(storage[pvtPos], storage[newPvtPos]);

    return newPvtPos;
}
