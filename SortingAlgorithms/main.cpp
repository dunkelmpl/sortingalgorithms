#define _CRTDBG_MAP_ALLOC  
#include <stdlib.h>  
#include <crtdbg.h> 

#include "SortingTester.h"
#include "BubbleSort.h"
#include "SelectionSort.h"
#include "InsertionSort.h"

int main()
{
    int result = 0;

    {
        vector<BaseSort*> sortTestInstances{
            new BubbleSort,
            new SelectionSort,
            new InsertionSort
        };

        for (auto&& sortTest : sortTestInstances) {
            result = (0 == result) && SortingTester::run(sortTest);

            delete sortTest;
        }
    }

    _CrtDumpMemoryLeaks();

    return result;
}