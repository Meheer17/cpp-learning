#include <iostream>
#include <vector>
#include "25.SignedArrayView.h"

int main()
{
    std::vector arr{9, 7, 5, 3, 1};
    SignedArrayView sarr{arr}; // Create a signed view of our std::vector

    for (auto index{sarr.ssize() - 1}; index >= 0; --index)
    {
        // std::cout << index;
        std::cout << sarr[index] << ' '; // index using a signed type
    }
    return 0;
}