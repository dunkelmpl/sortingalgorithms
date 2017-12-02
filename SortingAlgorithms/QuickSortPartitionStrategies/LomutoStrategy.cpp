#include "LomutoStrategy.h"

int LomutoStrategy::partition(int left, int right)
{
    int pvtPos = right;
    int newPvtPos = left;

    vector<int>& storage = this->getStorage();

    for (int pos = left; pos < right; pos++) {
        if (storage[pos] <= storage[pvtPos]) {
            swap(storage[pos], storage[newPvtPos]);
            newPvtPos++;
        }
    }

    swap(storage[pvtPos], storage[newPvtPos]);

    return newPvtPos;
}
