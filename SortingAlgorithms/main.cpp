#include "SortingTester.h"
#include "BubbleSort.h"
#include "SelectionSort.h"
#include "InsertionSort.h"

int main()
{
    int result = 0;

    vector<AbstractSort*> sortTestInstances{
        new BubbleSort(),
        new SelectionSort(),
        new InsertionSort()
    };

    for (auto&& sortTest : sortTestInstances) {
        result = (0 == result) && SortingTester::run(sortTest);

        delete sortTest;
    }

    return result;
}