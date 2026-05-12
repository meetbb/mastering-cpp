/* Solution to find if the array contains duplicates. */
#include "ContainsDuplicate.h"
#include <vector>
#include <unordered_set>
using namespace std;

bool ContainsDuplicate::containsDuplicate(vector<int>& nums) {
    unordered_set<int> seen;
    /* In Java, we used Hashset to check for the unique elements of array.
    Same functionality can be achieved in C++ using unordered_set.*/
    for (int num : nums)
    {
        if (seen.count(num))
        {
            return true;
        }
        seen.insert(num);
    }
    // When all elements in the array are unique, return false because there are no duplicates.
    return false;        
}