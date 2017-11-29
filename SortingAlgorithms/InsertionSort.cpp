#include "InsertionSort.h"

void InsertionSort::sort()
{
    for (size_t pos = 1; pos < storage.size(); pos++) {
        int newMin = storage[pos];
        size_t left = pos;

        while ((left > 0) && newMin < storage[left - 1]) {
            storage[left] = storage[left - 1];
            left--;
        }

        if (left != pos) {
            this->storage[left] = newMin;
        }
    }
}