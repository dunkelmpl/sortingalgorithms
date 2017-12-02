#include "StlSort.h"

#include <algorithm>

using namespace std;

void StlSort::sort()
{
    std::sort(this->storage.begin(), this->storage.end());
}
