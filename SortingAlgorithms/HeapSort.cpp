#include "HeapSort.h"

void HeapSort::sort()
{
    heapify();

    int siftSize = storage.size() - 1;

    while (siftSize > 0) {
        swap(storage[0], storage[siftSize]);

        siftDown(0, siftSize--);
    }
}

void HeapSort::heapify()
{
    int storageSize = storage.size();

    for (int top = (storageSize >> 1) - 1; top >= 0; top--) {
        siftDown(top, storageSize);
    }
}

void HeapSort::siftDown(size_t top, size_t size)
{
    size_t leftChild = 2 * top + 1;
    size_t rightChild = 2 * top + 2;
    size_t largest = top;

    if (leftChild < size && storage[leftChild] > storage[largest]) {
        largest = leftChild;
    }

    if (rightChild < size && storage[rightChild] > storage[largest]) {
        largest = rightChild;
    }

    if (largest != top) {
        swap(storage[largest], storage[top]);

        siftDown(largest, size);
    }
}