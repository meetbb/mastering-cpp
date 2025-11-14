#include <iostream>
#include <vector>
#include "TwoPointerSkeleton.h"

int main() {
    std::vector<int> arr = {-3, -1, 0, 1, 2};        
    int target = -2;
    if (twoSum(arr, target))
    {
        std::cout << "There is a sum.";
    }
    else
    {
        std::cout << "false";
    }    
    return 0;
}