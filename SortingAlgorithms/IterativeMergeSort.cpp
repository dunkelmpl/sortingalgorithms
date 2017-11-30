#include "IterativeMergeSort.h"

void IterativeMergeSort::sort()
{
    for (size_t size = 1, dblSize = size << 1; size <= storage.size(); size = dblSize, dblSize = size << 1) {

        for (size_t left = 0; left < storage.size(); left += dblSize) {
            size_t middle = left + size - 1;
            size_t right = middle + size;

            if (right >= storage.size()) {
                right = storage.size() - 1;
            }

            if (middle < right) {
                this->merge(left, middle, right);
            }
        }
    }
}
