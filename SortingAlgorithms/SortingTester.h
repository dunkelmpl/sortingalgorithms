#pragma once
#include "BaseSort.h"

class SortingTester {
public:
    static int run(BaseSort* sort) { return sort->runTests(); }
};