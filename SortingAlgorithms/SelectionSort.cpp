#include "SelectionSort.h"

void SelectionSort::sort()
{
    for (size_t start = 0; start < storage.size() - 1; start++) {
        size_t minIndex = start;
    
        for (size_t chk = start + 1; chk < storage.size(); chk++) {
            if (storage[chk] < storage[minIndex]) {
                minIndex = chk;
            }
        }

        if (minIndex != start) {
            this->swap(storage[start], storage[minIndex]);
        }
    }
}
