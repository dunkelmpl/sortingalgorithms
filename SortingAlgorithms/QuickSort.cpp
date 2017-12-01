#include "QuickSort.h"

void QuickSort::sort()
{
    this->sortChunk(0, storage.size() - 1);
}

void QuickSort::sortChunk(int left, int right)
{
    while (left < right) {
        int pivot = this->partition(left, right);

        if (pivot - left > right - pivot) { //left side is bigger
            this->sortChunk(left, pivot - 1);
            left = pivot + 1;
        }
        else {
            this->sortChunk(pivot + 1, right);
            right = pivot - 1;
        }
    }

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
