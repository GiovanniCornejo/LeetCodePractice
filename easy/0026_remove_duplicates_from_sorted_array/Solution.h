/**
 * Given an integer array nums sorted in non-decreasing order,
 * remove the duplicates in-place such that each unique element appears only once.
 * The relative order of the elements should be kept the same. Then return the number of unique elements in nums.
 *
 * Consider the number of unique elements of nums to be k, to get accepted, you need to do the following things:
 * Change the array nums such that the first k elements of nums contain the unique elements in the order they were present in nums initially.
 * The remaining elements of nums are not important as well as the size of nums.
 * Return k.
 *
 * Example:
 *      Input: nums = [1,1,2]
 *      Output: 2, nums = [1,2,_]
 *      Explanation: Your function should return k = 2, with the first two elements of nums being 1 and 2 respectively.
 *
 * Constraints:
 *      1 <= nums.length <= 3 * 10^4
 *      -100 <= nums[i] <= 100
 *      nums is sorted in non-decreasing order.
 */

#ifndef SOLUTION_H
#define SOLUTION_H

#include <vector>

class Solution
{
public:
    int removeDuplicates(std::vector<int> &nums)
    {
        int k = 0;

        for (int i = 0; i < nums.size(); ++i)
        {
            // Skip repeat values by using k (count) as index
            if (k == 0 || nums[k - 1] != nums[i])
            {
                nums[k] = nums[i];
                ++k;
            }
        }

        return k;
    }
};

#endif // SOLUTION_H