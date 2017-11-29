#include "SortingTester.h"
#include "BubbleSort.h"
#include "SelectionSort.h"

int main()
{
    return (
        0 == SortingTester::run(new BubbleSort) && 
        0 == SortingTester::run(new SelectionSort)
    );
}