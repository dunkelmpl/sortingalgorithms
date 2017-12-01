#pragma once
#include <vector>

using namespace std;

class BaseSort {
public:
    BaseSort() : storage(0) {};
    BaseSort(int input[], size_t size) : storage(input, input + size) {};
    virtual ~BaseSort() {};
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
    void swap(int& item1, int& item2);

protected:
    void assertSorted(bool expectAscending = true);

private:
    int* generateRandomInput(size_t size, int min = 0, int max = 1000);

protected:
    vector<int> storage;
};