#define _CRTDBG_MAP_ALLOC  
#include <stdlib.h>  
#include <crtdbg.h> 

#include "SortingTester.h"
#include "BubbleSort.h"
#include "SelectionSort.h"
#include "InsertionSort.h"
#include "MergeSort.h"
#include "IterativeMergeSort.h"
#include "HeapSort.h"
#include "QuickSort.h"

int main()
{
    int result = 0;

    {
        vector<BaseSort*> sortTestInstances{
            new BubbleSort,
            new SelectionSort,
            new InsertionSort,
            new MergeSort,
            new IterativeMergeSort,
            new HeapSort,
            new QuickSort,
        };

        for (auto&& sortTest : sortTestInstances) {
            if (0 == result) {
                result = SortingTester::run(sortTest);
            }

            delete sortTest;
        }
    }

    _CrtDumpMemoryLeaks();

    return result;
}