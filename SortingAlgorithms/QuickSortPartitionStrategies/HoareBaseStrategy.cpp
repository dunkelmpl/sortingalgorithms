#include "HoareBaseStrategy.h"

int HoareBaseStrategy::partition(int left, int right)
{
    int pvtPos = this->getStartPivotIndex(left, right);

    int leftPos = left;
    int rightPos = right;

    vector<int>& storage = this->getStorage();
    int pvtValue = storage[pvtPos];

    while (true) {
        
        while (storage[leftPos] < pvtValue) {
            leftPos++;
        }

        while (storage[rightPos] > pvtValue) {
            rightPos--;
        }

        if (leftPos >= rightPos) {
            break;
        }

        /*
        * After swapping of leftPos and rightPos items we have to
        * unconditionally shift both positions to avoid infinite loop
        * for the case when storage[leftPos] == storage[rightPos] == pvtValue
        */
        swap(storage[leftPos++], storage[rightPos--]);
    }

    //rightPos supposed to be the same here
    return rightPos;
}
