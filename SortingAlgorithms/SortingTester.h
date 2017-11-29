#pragma once
#include "AbstractSort.h"

class SortingTester {
public:
    static int run(AbstractSort* sort) { return sort->runTests(); }
};