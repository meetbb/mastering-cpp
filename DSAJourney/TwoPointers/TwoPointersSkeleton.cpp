/* When do we use Two Pointer technique?
    1. Sorted Input: If the array or list is already sorted (or can be sorted), two pointers can efficiently find pairs or ranges.
        Example: Find two numbers in a sorted array that add up to a target.
    2. Pairs or Subarrays: When the problem asks about two elements, subarrays, or ranges instead of working with single elements.
        Example: Longest substring without repeating characters, maximum consecutive ones, checking if a string is palindrome.
    3. Sliding Window Problems: When you need to maintain a window of elements that grows/shrinks based on conditions.
        Example: Find smallest subarray with sum ≥ K, move all zeros to end while maintaining order.
    4. Linked Lists (Slow-fast pointers): Detecting cycles, finding the middle node, or checking palindrome property.
        Example: Floyd's Cycle Detection Algorithm (Tortoise and Hare).
*/
#include <iostream>
#include <vector>

using namespace std;

bool twoSum(vector<int> &arr, int target) {
    int left = 0, right = arr.size() - 1;
    while (left < right)
    {
        int sum = arr[left] + arr[right];
        if (sum == target)
        {
            return true;
        } else if (sum < target)
        {
            left++;
        } else
        {
            right--;
        }        
    }
    return false;
}

int main() {
    vector<int> arr = {-3, -1, 0, 1, 2};        
    int target = -2;
    if (twoSum(arr, target))
    {
        cout << "true";
    }
    else
    {
        cout << "false";
    }    
    return 0;
}