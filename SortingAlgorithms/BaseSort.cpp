#include "BaseSort.h"

#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include <cassert>

using namespace std;

int BaseSort::runTests(size_t numTests /* = 10 */)
{
    srand((unsigned)time(nullptr));

    for (size_t test = 0; test < numTests; test++) {

        cout << "Test #" << (test + 1) << ":\n";

        size_t size = (rand() % 100) + 1;
        int* input = generateRandomInput(size);

        this->setStorage(input, size);

        delete[] input;

        this->print("Original");

        this->sort();

        this->print("Sorted");

        this->assertSorted();

        cout << '\n';
    }

    return 0;
}

void BaseSort::assertSorted(bool expectAscending /* = true */)
{
    assert(
        ([=]() -> bool {
            for (vector<int>::iterator &it = this->storage.begin(); it != this->storage.end() - 1; it++) {
                int cmp = *it - *(it + 1);
                bool failed = expectAscending ? cmp > 0 : cmp < 0;

                if (failed) {
                    return false;
                }
            }

            return true;
        }())
    );
}

void BaseSort::print(char* title)
{
    cout << title << ": ";
    for (auto &item : storage) {
        cout << item << ' ';
    }

    cout << endl;
}

void BaseSort::setStorage(int input[], size_t size)
{
    this->setStorage(vector<int>(input, input + size));
}

void BaseSort::setStorage(vector<int> storage)
{
    this->storage = storage;

}

int* BaseSort::generateRandomInput(size_t size, int min /* = 0 */, int max /* = 1000 */)
{
    int* input = new int[size];

    for (size_t ind = 0; ind < size; ind++) {
        input[ind] = (rand() % (max + 1 - min)) + min;
    }

    return input;
}

void BaseSort::swap(int& item1, int& item2)
{
    int tmp = item1;
    item1 = item2;
    item2 = tmp;
}