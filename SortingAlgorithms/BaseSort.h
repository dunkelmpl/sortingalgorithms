#pragma once
#include <vector>

using namespace std;

class BaseSort {
public:
    BaseSort() : storage(0) {};
    BaseSort(int input[], size_t size) : storage(input, input + size) {};
    virtual ~BaseSort() {};
public:
    int runTests(const string& testName, bool verbose = false, size_t numTests = 100, size_t arrSize = 100);

public:
    virtual void sort() = 0;
    void print(char* title);

public:
    void setStorage(int input[], size_t size);
    void setStorage(vector<int> storage);
    vector<int>& getStorage() { return storage; }

protected:
    void swap(int& item1, int& item2);

protected:
    void assertSorted(bool expectAscending = true);

private:
    int* generateRandomInput(size_t size, int min = 0, int max = 1000);

protected:
    vector<int> storage;
};
