#include "MergeSort.h"

void MergeSort::sort()
{
    this->sortChunk(0, storage.size() - 1);
}

void MergeSort::sortChunk(size_t start, size_t end)
{
    if (start == end) {
        return;
    }

    size_t middle = (start + end) >> 1;

    this->sortChunk(start, middle);
    this->sortChunk(middle + 1, end);

    this->merge(start, middle, end);
}

void MergeSort::merge(size_t start, size_t middle, size_t end)
{
    vector<int> leftTmp(storage.begin() + start, storage.begin() + middle + 1);
    vector<int> rightTmp(storage.begin() + middle + 1, storage.begin() + end + 1);

    size_t left = 0;
    size_t right = 0;
    size_t pos = start;

    while (left < leftTmp.size() && right < rightTmp.size()) {
        if (leftTmp[left] <= rightTmp[right]) {
            storage[pos++] = leftTmp[left++];
        }
        else {
            storage[pos++] = rightTmp[right++];
        }
    }

    while (left < leftTmp.size()) {
        storage[pos++] = leftTmp[left++];
    }

    while (right < rightTmp.size()) {
        storage[pos++] = rightTmp[right++];
    }
}