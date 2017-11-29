#include "BubbleSort.h"

using namespace std;

void BubbleSort::sort()
{
    bool swapped = false;
    size_t numUnsorted = storage.size();

    do {
        swapped = false;

        for (size_t ind = 1; ind < numUnsorted; ind++) {
            if (storage[ind - 1] > storage[ind]) {
                this->swap(storage[ind - 1], storage[ind]);
                swapped = true;
            }
        }

        numUnsorted--;
    } while (swapped && (numUnsorted > 0));
}

