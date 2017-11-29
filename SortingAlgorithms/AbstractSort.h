#pragma once
#include <vector>

using namespace std;

class AbstractSort {
public:
    AbstractSort() : storage(0) {};
    AbstractSort(int input[], size_t size) : storage(input, input + size) {};

public:
    int runTests(size_t numTests = 10);

public:
    virtual void sort() = 0;
    void print(char* title);

public:
    void setStorage(int input[], size_t size);
    void setStorage(vector<int> storage);
    inline vector<int> getStorage() const { return storage; };

protected:
    void assertSorted(bool expectAscending = true);

private:
    int* generateRandomInput(size_t size, int min = 0, int max = 1000);

protected:
    vector<int> storage;
};