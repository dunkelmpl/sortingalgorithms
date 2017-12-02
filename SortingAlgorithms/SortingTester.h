#pragma once
#include "BaseSort.h"

class SortingTester {
public:
    static int run(
        BaseSort *const sort,
        const string testName,
        bool verbose = false,
        size_t numTests = 100,
        size_t arrSize = 100
    ) {
        return sort->runTests(testName, verbose, numTests, arrSize);
    }
};
