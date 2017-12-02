#define _CRTDBG_MAP_ALLOC  
#include <stdlib.h>  
#include <crtdbg.h> 

#include <iostream>
#include <string>
#include <time.h>

#include "STLSort.h"
#include "SortingTester.h"
#include "BubbleSort.h"
#include "SelectionSort.h"
#include "InsertionSort.h"
#include "MergeSort.h"
#include "IterativeMergeSort.h"
#include "HeapSort.h"
#include "QuickSort.h"
#include "QuickSortPartitionStrategies/LomutoStrategy.h"
#include "QuickSortPartitionStrategies/HoareMedianOf3IndexStrategy.h"
#include "QuickSortPartitionStrategies/HoareMiddleIndexStrategy.h"
#include "QuickSortPartitionStrategies/HoareRandomIndexStrategy.h"

typedef struct {
    BaseSort* sortInstance;
    const string testName;
} TestCase;

int main()
{
    int result = 0;

    {
        srand((unsigned)time(nullptr));

        LomutoStrategy lomutoQuickSortStrategy;
        HoareMiddleIndexStrategy hoareMiddleIndexQuickSortStrategy;
        HoareRandomIndexStrategy hoareRandomIndexQuickSortStrategy;
        HoareMedianOf3IndexStrategy hoareMedianOf3IndexStrategy;

        vector<TestCase> sortTestInstances {
            {new BubbleSort, "Bubble sort" },
            {new SelectionSort , "Selection sort" },
            {new InsertionSort, "Insertion sort" },
            {new MergeSort , "Merge sort" },
            {new IterativeMergeSort , "Iterative merge sort" },
            {new HeapSort , "Heap sort" },
            {new QuickSort(lomutoQuickSortStrategy) , "Quick sort (Lomuto scheme)" },
            {new QuickSort(hoareMiddleIndexQuickSortStrategy) , "Quick sort (Hoare scheme with middle index)" },
            {new QuickSort(hoareRandomIndexQuickSortStrategy) , "Quick sort (Hoare scheme with random index)" },
            {new QuickSort(hoareMedianOf3IndexStrategy) , "Quick sort (Hoare scheme with median of 3 index)" },
            {new StlSort, "Built-in sort (std::sort())" },
        };

        size_t numTests = 100;
        size_t arrSize = 10000;
        cout <<
            "\n-----------------------------------------------------------------------------------\n" <<
            "Running " << numTests <<
            " tests for every sorting algorithm with random arrays of len = " << arrSize <<
            "\n-----------------------------------------------------------------------------------\n\n";

        for (auto& sortTest : sortTestInstances) {
            if (0 == result) {
                result = SortingTester::run(sortTest.sortInstance, sortTest.testName, false, numTests, arrSize);
            }

            delete sortTest.sortInstance;
        }

        cout << "\n-----------------------------------------------------------------------------------\nDone\n\n";
    }

    _CrtDumpMemoryLeaks();

    return result;
}
