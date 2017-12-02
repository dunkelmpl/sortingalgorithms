#include "QuickSort.h"

QuickSort::QuickSort(BaseStrategy& ps) : partitionStrategy(ps)
{
    partitionStrategy.setQuickSortInstance(this);
}

QuickSort::QuickSort(int input[], size_t size, BaseStrategy& ps)
    : BaseSort(input, size), partitionStrategy(ps)
{
    partitionStrategy.setQuickSortInstance(this);
}

void QuickSort::sort()
{
    this->sortChunk(0, storage.size() - 1);
}

void QuickSort::sortChunk(int left, int right)
{
    while (left < right) {
        if (shouldUseInsertionSort(left, right)) {
            this->insertionSort(left, right);
            break;
        }

        int pivot = this->partition(left, right);

        if (pivot - left > right - pivot) { //left side is bigger
            if (this->isPivotAutoSorted()) {
                this->sortChunk(left, pivot - 1);
                left = pivot + 1;
            }
            else {
                this->sortChunk(left, pivot);
                left = pivot;
            }
        }
        else {
            this->sortChunk(pivot + 1, right);
            right = pivot;
            if (this->isPivotAutoSorted()) {
                right--;
            }
        }
    }
}

int QuickSort::partition(int left, int right)
{
    return this->partitionStrategy.partition(left, right);
}

bool QuickSort::isPivotAutoSorted()
{
    return this->partitionStrategy.isPivotAutoSorted();
}

bool QuickSort::shouldUseInsertionSort(int left, int right)
{
    return right - left + 1 < insSortUseThreshold;
}

void QuickSort::insertionSort(int left, int right)
{
    InsertionSort ins;
    ins.sort(this->storage, left, right + 1);
}
