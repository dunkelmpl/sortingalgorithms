#include "InsertionSort.h"

void InsertionSort::sort()
{
    this->sort(storage);
}

void InsertionSort::sort(vector<int>& customStorage, int start /* = 0 */, int end /* = -1 */)
{
    if (end < 0) {
        end = customStorage.size();
    }

    for (int pos = start + 1; pos < end; pos++) {
        int newMin = customStorage[pos];
        int left = pos;

        while ((left > 0) && newMin < customStorage[left - 1]) {
            customStorage[left] = customStorage[left - 1];
            left--;
        }

        if (left != pos) {
            customStorage[left] = newMin;
        }
    }
}
