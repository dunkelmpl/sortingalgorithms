#include "BaseSort.h"

#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include <cassert>
#include <chrono>


using namespace std;

int BaseSort::runTests(
    const string& testName,
    bool verbose /* = false */,
    size_t numTests /* = 100 */,
    size_t arrSize /* = 100 */
) {
    auto getMilliseconds = []() {
        using namespace std::chrono;
        return duration_cast<milliseconds>(
            system_clock::now().time_since_epoch()
        );
    };

    srand((unsigned)time(nullptr));

    int** inputs = new int*[numTests];
    for (size_t test = 0; test < numTests; test++) {
        inputs[test] = generateRandomInput(arrSize);
    }

    cout.width(50);
    cout << left << testName << " : ";

    chrono::milliseconds startTime = getMilliseconds();
    for (size_t test = 0; test < numTests; test++) {

        if (verbose) {
            cout << "\nTest #" << (test + 1) << ":\n";
        }

        this->setStorage(inputs[test], arrSize);

        delete[] inputs[test];

        if (verbose) {
            this->print("Original");
        }

        this->sort();

        if (verbose) {
            this->print("Sorted");
        }

        this->assertSorted();
    }

    chrono::milliseconds endTime = getMilliseconds();

    delete[] inputs;

    cout.width(5);
    cout << right << (endTime.count() - startTime.count()) << "(ms)" << endl;

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
